import styled from 'styled-components';
import background from '../../assets/home/background.jpg';
import {ContainerImage} from "../../components/global";
import {Link} from 'react-router-dom';

export const Redirect = styled(Link)`
  width: 50%;
`;

export const IconSection = styled.div`
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  align-self: center;
  margin-bottom: 10px;
`;

export const Icon = styled.img`
  width: 50px;
  height: 60px;
  display: flex:
  align-self: center;
`;

export const ContainerProfile = styled(ContainerImage)`
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
  background-color: rgba(36, 0, 70, 0.5);
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