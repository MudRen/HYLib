inherit SKILL;
#include <ansi.h>;
// [lsg 1999/11/20]
mapping *quest = ({
        ([      "quest":                "������",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "�䵱��",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "������",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "��ɽ��",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "���չ�",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            80,
                "score" :               20
        ]),
        ([      "quest":                "�һ���",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            80,
                "score" :               20
        ]),
        ([      "quest":                "������",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "����ɽ��",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "������",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "ѩɽ��",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),

        ([      "quest":                "������",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "����",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),

        ([      "quest":                "��Ĺ��",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            400,
                "pot_bonus":            150,
                "score" :               20
        ]),
        ([      "quest":                "ؤ��",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "ȫ���",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "����μ�",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "��ң��",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "���ư�",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "����Ľ��",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "������",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "�������",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "������",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "�嶾��",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "����Ľ��",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            50,
                "score" :               20
        ]),

        ([      "quest":                "����",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "����������",
                "quest_type":           "׽��",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            50,
                "score" :               20
        ]),

});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
