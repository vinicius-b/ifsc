CREATE TABLE aluno(
	nome varchar(128),
	documento char(11) primary key,
	telefone bigint,
	email varchar(128)
)
CREATE TABLE curso (
	????????
)

CREATE TABLE matricula (
	aluno char(11),
	curso ???,
	numero char(10) primary key,
	constraint fk_matricula_aluno_aluno_documento
		foreign key (aluno) references aluno(documento)
)
