filename = 'C:/Users/20221en20108/Documents/LingProgGit/Pratica8/data.bin';

fid = fopen(filename, 'r');
if fid == -1
    error('Erro ao abrir o arquivo.');
end

bloco = input('Digite o número do bloco que deseja ler (começando do 0): ');
tamanho_bloco = 10; % tamanho fixo do bloco em bytes

if bloco < 0
    error('Número de bloco inválido.');
end

offset = bloco * tamanho_bloco;
status = fseek(fid, offset, 'bof'); % posiciona no offset

if status ~= 0
    error('Erro ao posicionar o cursor no arquivo.');
end

buffer = fread(fid, tamanho_bloco, '*char')'; % lê o bloco e transpõe para string

if isempty(buffer)
    disp('Não há dados para ler nesta posição.');
else
    fprintf('Conteúdo do bloco %d: %s\n', bloco, buffer);
end

fclose(fid);
