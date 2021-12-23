import styled from 'styled-components';
import background from '../../assets/signUp/background.png';
import {ContainerImage} from "../../components/global";
import {Link} from 'react-router-dom';

export const Redirect = styled(Link)`
  width: 50%;
`;

export const ContainerSignUp = styled(ContainerImage)`
  min-height: 100vh;
  justify-content: center;
  align-items: center;
  background: url(${background}) fixed;
  background-size: cover;
`;

export const Section = styled.div`
  width: 60%;
  padding: 50px;
  height: auto;
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  /* background-color: rgba(36, 0, 70, 0.5); */
  background-color: ${({ theme }) => theme.colors.cardBackground};
  border: 1px solid #6B33FF;
  border-radius: 15px;
  backdrop-filter: blur(20px);
`;

export const Form = styled.div`
  width: 100%;
  height: auto;
  display: grid;
  grid-template-columns: 1fr 1fr;
`;

export const ButtonSection = styled.div`
  width: 50%;
  display: flex;
  justify-content: space-around;
  align-self: end;
`;