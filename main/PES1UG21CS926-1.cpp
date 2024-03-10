pipeline {
    agent any
    
    stages {
        stage('Build') {
            steps {
                script {
                    build 'PES1UG21CS926-1'
                    sh 'g++ main1.cpp -o output'
                }
            }
        }
        stage('Test') {
            steps {
                script {
                    sh './output'
                }
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying...'
            }
        }
    }
    
    post {
        failure {
            echo 'Pipeline failed'
        }
    }
}