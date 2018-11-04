// jiuyin-zhengong.c �����湦
#include <ansi.h>

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int lev = (int)me->query_skill("jiuyin-zhengong", 1);
	if (!me->query("jiuyin/full") && !me->query("jiuyin/shang") && !me->query("jiuyin/gumu"))
		return notify_fail("����ͼѧϰ�����湦�����ƺ����޽�չ��\n");
	if (!me->query("jiuyin/full") && !me->query("jiuyin/shang") && me->query("jiuyin/gumu") && lev > 100)
		return notify_fail("����ͼѧϰ�����湦�����ƺ����޽�չ��\n");
	if ((int)me->query_skill("force", 1) < 200)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧϰ�����湦��\n");
	if (lev > 100 && lev > (int)me->query_skill("daode-jing", 1) && (int)me->query_skill("daode-jing", 1) < 200)
		return notify_fail("��ĵ��¾���򲻹���ǿ�����������湦�ᵼ���߻���ħ��\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("�����湦ֻ���ж�(yandu)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"jiuyin-zhengong/" + func;
}

mapping exercise_msg(object me)
{
    return ([
	"status_msg" : HIB + me->name() + "˫��΢�գ���һ�ɾ�������Χ������" NOR,
	"start_my_msg" : HIB"���������£�˫Ŀ΢�գ�˫���������������̫�������˺�һ���������顣\n"NOR,
	"start_other_msg" : HIB + me->name() + "�������£�˫Ŀ΢�գ�˫���������������̫������紵����" + me->name() + "���ϵ����۾�Ȼ��Ϊ������\n"NOR,
	"halt_msg" : "$N����΢΢����������������վ��������\n",
	"end_my_msg" : "�㽫��Ϣ������һ��С���죬�������뵤�˫��һ��վ��������\n",
	"end_other_msg" : me->name() + "�����϶�Ȼһ������������ȥ���漴˫��һ��վ��������\n"
    ]);
}

void skill_improved(object me)
{
         int i =3 +random(8);
         if( me->query_skill("jiuyin-zhengong", 1) > 200
          && me->query("jiuyin/gift") + 200 < me->query_skill("jiuyin-zhengong", 1)){
             if( !me->query("jiuyin/gift"))
               me->set("jiuyin/gift", me->query_skill("jiuyin-zhengong", 1) -200);
             else 
               me->add("jiuyin/gift", 1);
             me->add("max_neili", i); 
             tell_object(me,HIW"\n���ž����湦����ߣ���о��Լ�����������"+chinese_number(i)+"�㡣\n"NOR);
         }
}
