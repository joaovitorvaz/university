# Apache Spark Stream

Neste tutorial, você aprende como implantar um aplicativo Apache Spark Streaming no Cloud Dataproc e processar mensagens do Cloud Pub/Sub quase em tempo real. O sistema que você constrói neste cenário gera milhares de tweets aleatórios, identifica hashtags de tendência em uma janela deslizante, salva os resultados no Cloud Datastore e exibe os resultados em uma página da web.

## Conteúdo deste repositório:

* `http_function`: Código Javascript para a função HTTP implantada no Cloud Functions.
* `spark`: Código Scala para o aplicativo de streaming Apache Spark.
* `tweet-generator`: Código Python para o gerador de tweet aleatório.

## Execução
-----------------

Iniciar o código teste:

```bash
cd spark
mvn test
```

Referência: 

https://cloud.google.com/solutions/using-apache-spark-dstreams-with-dataproc-and-pubsub
