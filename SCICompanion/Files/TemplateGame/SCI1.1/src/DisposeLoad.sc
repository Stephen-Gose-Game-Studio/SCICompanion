(version 2)
(include "sci.sh")
(exports
    0 DisposeLoad
)
(script 958)



(procedure public (DisposeLoad param1 param2)
    (var temp0, temp1)
    = paramTotal (- paramTotal 2)
    = temp0 0
    (while (<= temp0 paramTotal)
        = temp1 param2[temp0]
        (if (param1)
            Load(param1 temp1)
        )(else
            DisposeScript(temp1)
        )
        ++temp0
    )
    DisposeScript(958)
)

