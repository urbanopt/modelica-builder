FROM openjdk:7-alpine

WORKDIR /usr/local/lib
RUN wget https://www.antlr.org/download/antlr-4.8-complete.jar
ENV CLASSPATH=".:/usr/local/lib/antlr-4.8-complete.jar:$CLASSPATH"

ENTRYPOINT ["java", "-jar", "/usr/local/lib/antlr-4.8-complete.jar"]
CMD []
