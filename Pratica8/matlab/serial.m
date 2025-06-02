filename = 'C:/Users/20221en20108/Documents/LingProgGit/Pratica8/test_file.txt';

fid = fopen(filename, 'r');
if fid == -1
    error('Erro ao abrir o arquivo.');
end

while ~feof(fid)
    line = fgetl(fid); % lê uma linha do arquivo
    disp(line)         % exibe a linha no console
end

fclose(fid);
