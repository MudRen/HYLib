
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) 
{ 
       if( (string)me->query("gender") != "Ů��" )
                return notify_fail("�����ľ���ֻ��Ů�Ӳ��������ڹ���\n");




return 1; 
}

int practice_skill(object me)
{
        return 
notify_fail("�����ľ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
           return __DIR__"ninemoonforce/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;

        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
                if( random(3*(me->query_skill("nine-moon-force"))) > (damage_bonus + 
foo) ) {
                        victim->receive_wound("jing", (damage_bonus + foo));
                        victim->apply_condition("ninemoonpoison", factor/2);
                        return 
"$N����ʽЮ��һ�������ޱȵľ���ʹ��$n�������˸����䡣\n";
                }
        }
        return foo;
}
 
int effective_level() { return 10;}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 5;
}
int black_white_ness()
{
	return -10;
}

