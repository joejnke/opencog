(define (check-conjunction var3)
    (if (or (string=? (cog-name var3) "conj_and") (string=? (cog-name var3) "conj_or") (string=? (cog-name var3) "conj_but"))
        (begin (stv 1 1))
        (begin (stv 0 1))
    )
)

(define conj
    (BindLink
        (VariableList
            (TypedVariableLink
                (VariableNode "$a-parse")
                (TypeNode "ParseNode")
            )
            (TypedVariableLink
                (VariableNode "$var1")
                (TypeNode "WordInstanceNode")
            )
            (TypedVariableLink
                (VariableNode "$var2")
                (TypeNode "WordInstanceNode")
            )
		    (TypedVariableLink
                (VariableNode "$pos")
                (TypeNode "DefinedLinguisticConceptNode")
            )
            (TypedVariableLink
                (VariableNode "$var3")
                (TypeNode "PrepositionalRelationshipNode")
            )
        )
        (AndLink
            (WordInstanceLink
                (VariableNode "$var1")
                (VariableNode "$a-parse")
            )
            (WordInstanceLink
                (VariableNode "$var2")
                (VariableNode "$a-parse")
            )
		    (PartOfSpeechLink
   				(VariableNode "$var1")
   				(VariableNode "$pos")
			)
		    (PartOfSpeechLink
                (VariableNode "$var2")
   				(VariableNode "$pos")
			)
            (EvaluationLink
   			    (VariableNode "$var3")		
   						(ListLink
      						(VariableNode "$var1")
      						(VariableNode "$var2")
   						)
            )
            (EvaluationLink
                (GroundedPredicateNode "scm: check-conjunction")
                (ListLink
                    (VariableNode "$var3")
                )
            )
        )
        (ListLink
            (ExecutionOutputLink
       	        (GroundedSchemaNode "scm: pre-conj-rule")
       	        (ListLink
                    (VariableNode "$var1")
                    (VariableNode "$var2")
                    (VariableNode "$var3")
                    (VariableNode "$pos")
                )
            )
        )
    )
)

(define (pre-conj-rule var1 var2 var3 pos)
  (ListLink 
    (and-rule (cog-name (word-inst-get-lemma  var1)) (cog-name var1)
              (cog-name (word-inst-get-lemma  var2)) (cog-name var2)
              (cog-name pos)
    )
  )
)