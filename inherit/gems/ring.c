#include <ansi.h>
#include <armor.h>

inherit FINGER;
inherit F_GEMS;

void init_sockets(object me)
{
	set("max_sockets", 1);
	if (me->query("combat_exp") > 10000000)
		add("max_sockets", 1);
	if (me->query("combat_exp") > 10000000)
		add("max_sockets", 1);

        if (me->query("combat_exp") < 10000000 && (int)query("sockets/max",1)>=2)
        set("sockets/max",2);

        if ((int)query("sockets/max",1)>3)
        set("sockets/max",3);

	if (me->query("diablo/" + TYPE_FINGER + "/id") != query("id")) return;

	set("sockets", me->query("diablo/" + TYPE_FINGER + "/sockets"));
	set_ring_desc();
}

void setup()
{
	init_sockets(this_player());
	::setup();
}

void spec_prop(object me, string socket, int socket_level, int mode)
{
int i;
	if (!valid_gem(socket, socket_level)) return;
if (me->query("diablo/" + TYPE_FINGER + "/id") != query("id")) return;
if (me->query("max_neili") < 100)  return;
	switch (socket) {
	case "ruby":
		if (mode == 1)
			message_vision(HIR + query("name") + HIR"���һ��ҫ�۵ĺ�⣬$N��������ԡ�¸е������쳣�ĳ��棡\n"NOR, me);
		else
			message_vision(HIR"������⽥������ȥ��$N�������ָֻ������ˡ�\n"NOR, me);
		me->add("max_qi", me->query("max_neili") * socket_level * mode / 15);
		me->add("eff_qi", me->query("max_neili") * socket_level * mode / 15);
		me->add("qi", me->query("max_neili") * socket_level * mode / 15);
		break;
	case "topaz":
		if (mode == 1)
			message_vision(HIY + query("name") + HIY"���һ����Ŀ�Ļƹ⣬$N��������ԡ�¸е������쳣�ĳ��棡\n"NOR, me);
		else
			message_vision(HIY"������⽥������ȥ��$N�ľ����ָֻ������ˡ�\n"NOR, me);
		me->add("max_jing", me->query("max_neili") * socket_level * mode / 40);
		me->add("eff_jing", me->query("max_neili") * socket_level * mode / 40);
		me->add("jing", me->query("max_neili") * socket_level * mode / 40);
		break;
	case "sapphire":
		if (mode == 1)
			message_vision(HIB + query("name") + HIB"���һ����͵����⣬$N��������ԡ�¸е������쳣�ĳ��棡\n"NOR, me);
		else
			message_vision(HIB"������⽥������ȥ��$N�������ָֻ������ˡ�\n"NOR, me);
		me->add("neili", me->query("max_neili") * socket_level * mode / 8);
		me->add("qi", me->query("max_qi") * socket_level * mode / 50);
		me->add("eff_qi", me->query("max_qi") * socket_level * mode / 50);
		me->add("jing", me->query("max_jing") * socket_level * mode / 50);
		me->add("eff_jing", me->query("max_jing") * socket_level * mode / 50);
		break;
	case "emerald":
		if (mode == 1)
			message_vision(HIG"��Ȼ��" + query("name") + HIG"��û���һ��������ɴ������Ů��Χ����$N����ߣ�\n"NOR, me);
		else
			message_vision(HIG"�̹�һ����$N������Ů��Ͳ����ˡ�\n"NOR, me);
		me->add("neili", me->query("max_neili") * socket_level * mode / 10);
		me->add_temp("apply/karey", 6 * socket_level * mode);
		break;
	case "amethyst":
		if (mode == 1)
			message_vision(MAG"һƬ��ɫ����Ѹ�ٴ�" + query("name") + MAG"��ӿ����ת�ۼ���Ѿ���$N����������\n"NOR, me);
		else
			message_vision(MAG"��ɫ�����紵ɢ�ˣ�$N�������������˳�����\n"NOR, me);
		me->add_temp("apply/dexerity", 6 * socket_level * mode);
		break;
	case "diamond":
		if (mode == 1)
			message_vision(HIW"��������" + query("name") + HIW"����һ������ֱ����ʣ�$Nɲʱ�е����ڳ�����������\n"NOR, me);
		else
			message_vision(HIW"������$N����ɫ�ָֻ���������\n"NOR, me);
		me->add_temp("apply/strength", 6 * socket_level * mode);
		break;
	case "skull":
		if (mode == 1)
			message_vision(WHT"$N��Ȼ�е�һ�����������Χ����$P������֮��ֻ���ó����Ī����ħ����\n"NOR, me);
		else
			message_vision(WHT"$N" + query("name") + WHT"�е����･��ʧȥ��Ч�ã�\n"NOR, me);
		me->add_temp("apply/magic", 6 * socket_level * mode);
		break;
	case "windjade":
		if (mode == 1)
			message_vision(GRN"$N��Ȼ�е�һ���Х��ת�ķ�Χ����$P��$N������Χ�γ����磡\n"NOR, me);
		else
			message_vision(GRN"$N" + query("name") + GRN"�е����･��ʧȥ��Ч�ã�\n"NOR, me);
		me->add("neili", me->query("max_neili") * socket_level * mode / 10);
		me->add_temp("apply/dodge", 7 * socket_level * mode);
		break;

	case "firejade":
		if (mode == 1)
			message_vision(WHT"$N��Ȼ�е����ȵ�����֮������$P��$N�������޾���������\n"NOR, me);
		else
			message_vision(WHT"$N" + query("name") + WHT"�е����･��ʧȥ��Ч�ã�\n"NOR, me);
		me->add("neili", me->query("max_neili") * socket_level * mode / 10);
		me->add("eff_qi", me->query("max_qi") * socket_level * mode / 8);
		me->add("eff_jing", me->query("max_jing") * socket_level * mode / 8);
		break;

	case "icejade":
		if (mode == 1)
			message_vision(CYN"$N��Ȼ�е�һ���ѩ�ĺ���Χ����$P��$N������������ã�\n"NOR, me);
		else
			message_vision(CYN"$N" + query("name") + CYN"�е����･��ʧȥ��Ч�ã�\n"NOR, me);
		me->add("neili", me->query("max_neili") * socket_level * mode / 10);
		me->add_temp("apply/karey", 5 * socket_level * mode);
		me->add_temp("apply/percao", 5 * socket_level * mode);
		break;

	case "thunderjade":
		if (mode == 1)
			message_vision(MAG"$N��Ȼ�е���ɫ�Ļ𣬰�ɫ���׵�Χ����$P��$N�������٣�\n"NOR, me);
		else
			message_vision(MAG"$N" + query("name") + MAG"�е����･��ʧȥ��Ч�ã�\n"NOR, me);
		me->add("neili", me->query("max_neili") * socket_level * mode / 10);
		me->add_temp("apply/intelligence", 3 * socket_level * mode);
		break;

	case "earthjade":
		if (mode == 1)
			message_vision(YEL"$N��Ȼ�е�����޾���������Χ����$P��$N�е�����������\n"NOR, me);
		else
			message_vision(YEL"$N" + query("name") + YEL"�е����･��ʧȥ��Ч�ã�\n"NOR, me);
		if ((int)me->query_temp("foodgem") < (socket_level*3))
		{
                me->add_temp("foodgem",1);
		if( me->query("food") < me->max_food_capacity() )
		me->set("food", me->max_water_capacity());
		if( (int)me->query("water") < me->max_water_capacity() )
		me->set("water", me->max_water_capacity());
		}
		me->add("neili", me->query("max_neili") * socket_level * mode / 10);
		me->add("max_jing", me->query("max_jing") * socket_level * mode / 8);
		break;
	}
	return;
}

int wear()
{
	int i, sockets, ret;
	object me = environment();

	if (!(ret = ::wear())) return 0;


	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), 1);
	return ret;
}

int unequip()
{
	int i, sockets, ret;
	object me = environment();

	if (!(ret = ::unequip())) return 0;

	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		spec_prop(me, query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)), -1);
	return ret;
}
