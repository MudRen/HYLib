// enable.c

#include <ansi.h>

inherit F_CLEAN_UP;

mapping valid_types = ([
	"unarmed":	"ȭ��",
	"sword":	"����",
	"hammer":     "����",
	"blade":	"����",
	"stick":	"����",
	"staff":	"�ȷ�",
	"club" :        "����",
"spear" :        "ǹ��",
	"throwing":	"����",
	"force":	"�ڹ�",
	"parry":	"�м�",
	"dodge":	"�Ṧ",
	"magic":	"����",
	"spells":	"ħ��",
        "leg":	"�ȷ�",
	
	"axe":	"����",
	"move":	"�ж�",
	"array":	"��",
	"whip":     "�޷�",
	"lingfa":  "�",

//	shaolin skills

	"finger":   "ָ��",
	"hand":     "�ַ�",
	"cuff":     "ȭ��",
	"claw":     "צ��",
	"strike":   "�Ʒ�",

//	"club":     "����",
]);

int main(object me, string arg)
{
	mapping map;
	string *types, *skill, ski, map_to;
	int i, modify;

	seteuid(getuid());

	if( !arg ) {
		map = me->query_skill_map();
		if( !mapp(map) || sizeof(map)==0 )
			return notify_fail("������û��ʹ���κ����⼼�ܡ�\n");

		skill = keys(valid_types);
		write("��������Ŀǰʹ���е����⼼�ܡ�\n");
		for (i=0; i<sizeof(skill); i++) {
			if( undefinedp(valid_types[skill[i]]) ) {
				map_delete(map, skill[i]);
				continue;
			}
			if( !me->query_skill(skill[i]) ) continue;
if (!undefinedp(map[skill[i]]) && me->query_skill(map[skill[i]],1)<=0)
{
		me->map_skill("unarmed");
		me->map_skill("hammer");
		me->map_skill("blade");
		me->map_skill("sword");
		me->map_skill("staff");
		me->map_skill("club");
		me->map_skill("throwing");
		me->map_skill("parry");
		me->map_skill("dodge");
		me->map_skill("magic");
		me->map_skill("spells");
		me->map_skill("leg");
		me->map_skill("axe");
		me->map_skill("array");
		me->map_skill("whip");	
		me->map_skill("finger");
		me->map_skill("hand");	
		me->map_skill("cuff");	
		me->map_skill("claw");	
		me->map_skill("strike");	
		me->map_skill("force");	
		
		me->prepare_skill("unarmed");
		me->prepare_skill("hammer");
		me->prepare_skill("blade");
		me->prepare_skill("sword");
		me->prepare_skill("staff");
		me->prepare_skill("club");
		me->prepare_skill("throwing");
		me->prepare_skill("parry");
		me->prepare_skill("dodge");
		me->prepare_skill("magic");
		me->prepare_skill("spells");
		me->prepare_skill("leg");
		me->prepare_skill("axe");
		me->prepare_skill("array");
		me->prepare_skill("whip");	
		me->prepare_skill("finger");
		me->prepare_skill("hand");	
		me->prepare_skill("cuff");	
		me->prepare_skill("claw");	
		me->prepare_skill("strike");	
                me->reset_action();
return notify_fail(HIR"����书������!������enable�����书\n"NOR);
}
			modify = me->query_temp("apply/" + skill[i]);
			printf("  %-20s�� %-20s  ��Ч�ȼ���%s%3d\n" NOR, 
				valid_types[skill[i]] + " (" + skill[i] + ")",
				undefinedp(map[skill[i]]) ? "��" : to_chinese(map[skill[i]]),
				(modify==0 ? "" : (modify>0 ? HIC : HIR)),
				me->query_skill(skill[i]));
		}
		return 1;
	}

	if( arg=="?" ) {
		write("�����ǿ���ʹ�����⼼�ܵ����ࣺ\n");
		skill = sort_array(keys(valid_types), (: strcmp :) );
		for(i=0; i<sizeof(skill); i++) {
			printf("  %s (%s)\n", valid_types[skill[i]], skill[i] );
		}
		return 1;
	}

	if( sscanf(arg, "%s %s", ski, map_to)!=2 )
		return notify_fail("ָ���ʽ��enable|jifa [<��������> <��������>|none]\n");

	if( undefinedp(valid_types[ski]) )
		return notify_fail("û������������࣬�� enable ? ���Բ鿴����Щ���ࡣ\n");

	if( map_to=="none" ) {
if (ski=="force")
{
if (me->query_temp("powerup"))
return notify_fail("����ڹ��㲻�ǻ�������?\n");
if (me->query_temp("linji"))
return notify_fail("����ڹ��㲻�ǻ�������?\n");
if (me->query_temp("yun_riyue"))
return notify_fail("����ڹ��㲻�ǻ�������?\n");
if (me->query_temp("yun_yinyang"))
return notify_fail("����ڹ��㲻�ǻ�������?\n");
        if( (int)me->query_temp("powerupxtg") ) return
            notify_fail("���Ѿ���������ˡ�\n");
        if( (int)me->query_temp("poweruptxg") ) return
            notify_fail("���Ѿ�����̫�����ˡ�\n");
        if( (int)me->query_temp("powerupkh") ) return
            notify_fail("���Ѿ����˿����޵й��ˡ�\n");
        if(me->query_temp("wdpowerup") )
        return notify_fail("����������ʹ�á��嶾�񹦡��ľ�������������״̬�·����书!\n"); 
        if ((int)me->query_temp("shield"))
                return notify_fail("���Ѿ����˻��������ˣ���������״̬�·����书!\n");

}
		me->map_skill(ski);
		me->reset_action();
		write("Ok.\n");
		return 1;
	} else if( map_to==ski ) {
		write("��" + to_chinese(ski) + "��������" + valid_types[ski] + "�Ļ���������Ҫ enable��\n");
		return 1;
	}

	if( !me->query_skill(map_to, 1) )
		return notify_fail("�㲻�����ּ��ܡ�\n");

//	if( !me->query_skill(ski, 1) )
//		return notify_fail("������" + to_chinese(ski) + "����ûѧ�ᣬ������"
//			+ to_chinese(map_to) + "�ˡ�\n");

	if( !SKILL_D(map_to)->valid_enable(ski) )
		return notify_fail("������ܲ��ܵ���������;��\n");

	
	if( ski=="magic" ) {
		write("�������һ�ַ���ϵ�������������¶�����\n");
		me->set("jingli", 0);
		me->receive_damage("jing", 0);
	} 
	else if( ski=="force" ) {
if (me->query_temp("powerup"))
return notify_fail("����ڹ��㲻�ǻ�������?\n");
if (me->query_temp("powerup"))
return notify_fail("����ڹ��㲻�ǻ�������?\n");
if (me->query_temp("linji"))
return notify_fail("����ڹ��㲻�ǻ�������?\n");
if (me->query_temp("yun_riyue"))
return notify_fail("����ڹ��㲻�ǻ�������?\n");
if (me->query_temp("yun_yinyang"))
return notify_fail("����ڹ��㲻�ǻ�������?\n");
        if( (int)me->query_temp("powerupxtg") ) return
            notify_fail("���Ѿ���������ˡ�\n");
        if( (int)me->query_temp("poweruptxg") ) return
            notify_fail("���Ѿ�����̫�����ˡ�\n");
        if( (int)me->query_temp("powerupkh") ) return
            notify_fail("���Ѿ����˿����޵й��ˡ�\n");
        if(me->query_temp("wdpowerup") )
        return notify_fail("����������ʹ�á��嶾�񹦡��ľ�������������״̬�·����书!\n"); 
        if ((int)me->query_temp("shield"))
                return notify_fail("���Ѿ����˻��������ˣ���������״̬�·����书!\n");

		write("�������һ���ڹ��������������¶�����\n");
		me->set("neili", 0);
		me->receive_damage("qi", 0);
	}
	me->map_skill(ski, map_to);
	me->reset_action();
	write("Ok.\n");

	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : enable|jifa [<��������> <��������> | none]
           enable|jifa ?

���ָ������ָ����Ҫ�õļ��ܣ���ָ����������ͼ������ơ�������Ӳ�
�������ʾ���������༰��Ŀǰ��ʹ�õļ������� �������һ�������г�
������ʹ�����⼼�ܵļ������ࡣ
 
HELP
        );
        return 1;
}
