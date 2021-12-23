/* eslint-disable jsx-a11y/anchor-is-valid */
import React, {useState} from 'react';
import {Link} from 'react-router-dom';
import {ContainerSignIn, Section, SignUp, Redirect, ButtonSection} from "./styles";
import Input from "../../components/input";
import Button from "../../components/button";

export default function SignIn() {

  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");

  return (
    <ContainerSignIn>
      <Section>
        <Input onChange={e => setEmail(e.target.value)} value={email} labelName="E-mail" size="80%" />
        <Input onChange={e => setPassword(e.target.value)} value={password} labelName="Senha" password={true} size="80%" />
        <SignUp>
          <p>Não possui uma conta? <Link to="/signUp"><b>Cadastre-se</b></Link></p>
        </SignUp>
        <ButtonSection>
          <Redirect to="/"><Button buttonName="Entrar" size="40%"/></Redirect>
        </ButtonSection>
      </Section>
    </ContainerSignIn>
  );
}