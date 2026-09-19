$AudioPath = "py_tools\data\self_songbie.mp3"
$VideoPath = "py_tools\output\video\self_songbie.mp4"

$AudioBitrate = "192k"

Write-Host "Audio: $AudioPath"
Write-Host "Video: $VideoPath"

$outputPath = "py_tools\output\sound\self_songbie.mp4"

ffmpeg -y -i "$VideoPath" -i "$AudioPath" -map 0:v:0 -map 1:a:0 -c:v copy -c:a aac -b:a $AudioBitrate -shortest "$outputPath"
# ffmpeg -i "py_tools\output\video\stft\05100835_music_stft.mp4" -i "py_tools\data\self_songbie.mp3" -c:v copy -c:a aac -map 0:v:0 -map 1:a:0 "py_tools\data\05100835_music_stft.mp4"
Write-Host "Done: $outputPath"