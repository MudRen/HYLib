// shenghuo-xinfa.c ʥ���ķ�
// by inca

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int practice_skill(object me)
{       
        return notify_fail("ʥ���ķ�ֻ��ͨ��ѧϰ(learn)�����!\n");
}
