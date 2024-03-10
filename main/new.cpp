pipeline { // The entire pipeline must be within a 'pipeline' block
    agent any

    stages {
        stage('Build') { 
            steps {
                script { 
                    build 'PES1UG21CS926-1' // Assuming 'build' is a Jenkins step
                    sh 'g++ new.cpp -o output' 
                }
            }
        }
        stage('Test') { 
            steps {
                sh './output' // No need for the 'script' block here 
            }
        }
        stage('Deploy') { 
            steps {
                echo "Deploying..." // Use double quotes for strings
            }
        }
    }

    post {
        failure {
            echo "Pipeline failed" // Use double quotes for strings
        }
    }
}
