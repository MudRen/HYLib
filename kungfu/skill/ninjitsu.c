// literate.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
    return 1;
}
int practice_skill(object me)
{
        return notify_fail("����ֻ����ѧ�ġ�\n");
} 
