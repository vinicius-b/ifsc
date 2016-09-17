CREATE TABLE aluno(
	nome varchar(128),
	documento char(11) primary key,
	telefone bigint,
	email varchar(128)
)
CREATE TABLE curso (
	numero char(8) primary key,
	chmin smallint,
	chmax smallint,
	nome varchar(128),
	campus varchar(128),
	curriculo char(5),
	curriculo char(8),
	constraint fk_curso_campus_campus_nome
		foreign key (campus) references campus(nome),
	constraint fk_curso_curriculo_curriculo_implantacao
		foreign key (curriculo) references curriculo(implantacao),
	constraint fk_curso_curriculo_curriculo_disciplina_codigo
		foreign key (curriculo) references curriculo(disciplina),
)

CREATE TABLE matricula (
	aluno char(11),
	curso char(8),
	numero char(10) primary key,
	constraint fk_matricula_aluno_aluno_documento
		foreign key (aluno) references aluno(documento),
	constraint fk_matricula_curso_curso_numero
		foreign key (curso) references curso(numero)
)
CREATE TABLE campus (
	nome varchar(128) primary key
)
