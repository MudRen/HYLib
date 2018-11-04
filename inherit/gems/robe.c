#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_GEMS;

void init_sockets(object me)
{
	set("max_sockets", 3);
	if (me->query("combat_exp") > 10000000)
		add("max_sockets", 1);

        if (me->query("combat_exp") < 10000000 && (int)query("sockets/max",1)>=3)
        set("sockets/max",3);

        if (me->query("combat_exp") < 20000000 && (int)query("sockets/max",1)>=4)
        set("sockets/max",4);

        if ((int)query("sockets/max",1)>5)
        set("sockets/max",5);

	if (me->query("diablo/" + TYPE_CLOTH + "/id") != query("id")) return;

	set("sockets", me->query("diablo/" + TYPE_CLOTH + "/sockets"));
	set_armor_desc();
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
	if (me->query("diablo/" + TYPE_CLOTH + "/id") != query("id")) return;
if (query("armor_prop/armor") < 20) return;
	switch (socket) {
	case "ruby":
		break;
	case "topaz":
		break;
	case "sapphire":
		break;
	case "emerald":
		break;
	case "amethyst":
		if (mode == 1)
			message_vision(MAG + query("name") + MAG"ɢ��һƬ��ɫ�ƹ⻷����$N������$P�������Ե�Խ��Խ���ʣ�\n"NOR, me);
		else
			message_vision(MAG"��ɫԽ��Խ����$N����������¶�˳�����\n"NOR, me);
		me->add_temp("apply/defense", 30 * socket_level * mode);
		break;
	case "diamond":
		if (mode == 1)
			message_vision(HIW"ֻ��$N���ϵ�" + query("name") + HIW"���澧���������������䣡\n"NOR, me);
		else
			message_vision(HIW"�����ģ�" + query("name") + HIW"�ƺ��ָֻ���Ѱ����\n"NOR, me);
              me->add_temp("apply/armor", query("armor_prop/armor") * socket_level * mode / 16);
		break;
	case "skull":
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

	remove_call_out("check_fight");
	call_out("check_fight", 1, me);

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

	remove_call_out("check_fight");

	return ret;
}

int spec_effect(object ob, object me, int damage, string socket, int socket_level)
{
	int i, def = 0;

	if (!valid_gem(socket, socket_level)) return def;
	if (me->query("diablo/" + TYPE_CLOTH + "/id") != query("id")) return 0;
	if (random(100) + me->query_temp("apply/magic") < 70) return def;

	switch (socket) {
	case "ruby":
		break;
	case "topaz":
		break;
	case "sapphire":
		break;
	case "emerald":
			i = damage * socket_level / 15;
if (i > (int)me->query("qi")/6) i=(int)me->query("qi")/6;
			if ((int)me->query("qi")< (int)me->query("max_qi"))
{
			message_vision(HIG"ֻ��$N���˿����������������������һЩ��\n"NOR, me);
			me->add("qi", i);
			me->add("eff_qi", i);
}

		if (!ob->query_condition("emerald_poison")) {
			message_vision(HIG"$n��У����ã�ֻ��һ������Ѹ�����쵽$p���ֱۣ�\n"NOR, me, ob);
			ob->apply_condition("snake_poison", ob->query_condition("snake_poison") + random(5) + 8);
			ob->apply_condition("zhizhu_poison", ob->query_condition("zhizhu_poison") + random(5) + 8);
			ob->apply_condition("wugong_poison", ob->query_condition("wugong_poison") + random(5) + 8);
			ob->apply_condition("xiezi_poison", ob->query_condition("xiezi_poison") + random(5) + 8);
			ob->apply_condition("chanchu_poison", ob->query_condition("chanchu_poison") + random(5) + 8);
			ob->apply_condition("emerald_poison", ob->query_condition("emerald_poison") + random(5) + 8);
			ob->set("emerald_poison", socket_level);
		}
		break;
	case "amethyst":
		break;

	case "windjade":
		message_vision(GRN"$nֻ��$N������Χ�γ����罫$p�Ĺ�����ȥ���٣�\n"NOR, me, ob);
		def = -damage * socket_level / 10;
			me->add("qi", socket_level*30);
			me->add("eff_qi", socket_level*30);
if (def < 1) def=1;

		break;
	case "firejade":
			i = damage * socket_level / 13;
		if (i > 0) {
			message_vision(RED"��Ȼ$N����������һ����$nֻ�е������ѵ����������ˣ�\n"NOR, me, ob);
if (i > (int)ob->query("qi")/5) i=(int)ob->query("qi")/5;
			ob->receive_damage("qi", i+socket_level*30);
			ob->receive_wound("qi", random(i)+socket_level*30);
			if (wizardp(me))
				tell_object(me, sprintf("�����˺����� %d\n", i));
		}
		break;
	case "icejade":
			i = damage;
		if (i > 0) {
			message_vision(CYN"��Ȼ$N��Χ�������죬�γ���һ��ˮ��ǽ,$n�Ĺ��������˻�����\n"NOR, me, ob);
if (i > (int)ob->query("qi")/6) i=(int)ob->query("qi")/6;
			ob->receive_damage("qi", i+socket_level*20);
			ob->receive_wound("qi", i+socket_level*20);
if (i > (int)ob->query("jing")/7) i=(int)ob->query("jing")/7;
			ob->receive_damage("jing", i+socket_level*20);
			if (wizardp(me))
				tell_object(me, sprintf("�����˺����� %d\n", i));
		}
		break;
	case "thunderjade":
			i = damage * socket_level / 15;
		if (i > 0) {
		message_vision(MAG"$N���ϵ��һ����$nֻ��ȫ��һ�飬��֪���룡\n"NOR, me, ob);
                        if (!ob->is_busy())
			ob->start_busy(random(socket_level)+2);
if (i > (int)ob->query("neili")/4) i=(int)ob->query("neili")/4;
			ob->add("neili", -i);
ob->start_busy(random(socket_level)+2);
}
		break;
	case "earthjade":
			i = damage * socket_level / 15;
			message_vision(YEL"$N����������Ĺ�â��Χ��$N���˺��˺ܶ࣡\n"NOR, me, ob);
if (i <=0) i=1;
if (i > (int)me->query("qi")/6) i=(int)me->query("qi")/6;
			if ((int)me->query("qi")< (int)me->query("max_qi"))
			me->add("qi", i);
			me->add("eff_qi", i);
if (i > (int)me->query("jing")/6) i=(int)me->query("jing")/6;
			if ((int)me->query("jing")< (int)me->query("max_jing"))
			me->add("jing", i);
			me->add("eff_jing", i);
		break;
	case "diamond":
		message_vision(HIW"$nֻ��$N�����ƺ���һ��������$p�ľ�����ȥ���٣�\n"NOR, me, ob);
		def = -damage * socket_level / 10;
if (def < 1) def=1;
			me->add("qi", socket_level*30);
			me->add("eff_qi", socket_level*30);
		break;
	case "skull":
		if (objectp(ob->query_temp("weapon")))
			i = damage * socket_level / 25;
		else
			i = damage * socket_level / 15;
		if (i > 0) {
			message_vision(WHT"��Ȼ$N��Χ������ʢ��$nֻ�е���Ѫ��ӿ���޷��Կأ�\n"NOR, me, ob);
if (i > (int)ob->query("qi")/5) i=(int)ob->query("qi")/5;
			ob->receive_damage("qi", i+socket_level*20);
			ob->receive_wound("qi", random(i)+socket_level*20);
			if (wizardp(me))
				tell_object(me, sprintf("�����˺����� %d\n", i));
		}
		break;
	}
	return def;
}

int ob_hit(object ob, object me, int damage)
{
	int i, sockets, ret = 0;

	sockets = query("sockets/max");
	for (i = 1; i <= sockets; i++)
		ret += spec_effect(ob, me, damage,
query(sprintf("sockets/socket%d", i)), query(sprintf("sockets/socket%d_level", i)));
	return ret;
}

void spec_recover(object me, string socket, int socket_level)
{
	int i;

//if (ob->query_temp("combat_yield")) return;
	if (!valid_gem(socket, socket_level)) return;
	if (me->query("diablo/" + TYPE_CLOTH + "/id") != query("id")) return;
        if ((int)me->query_temp("combat_yield")==1) return;
	if (random(100) + me->query_temp("apply/magic") < 70) return;

	switch (socket) {
	case "ruby":
		if (me->query("max_qi") > me->query("eff_qi") || me->query("eff_qi") > me->query("qi")
		&& random(2)==0) {
			message_vision(HIR"ֻ��$N���˿ں��������Ѫ����ʱֹס�ˣ����˿��ƺ�Ҳ��ʼ�������ϣ�\n"NOR, me);
			me->add("eff_qi", 40 * socket_level);
			if (me->query("eff_qi") > me->query("max_qi"))
				me->set("eff_qi", me->query("max_qi"));
			me->add("qi", 70 * socket_level);
			if (me->query("qi") > me->query("eff_qi"))
				me->set("qi", me->query("eff_qi"));
		}
		break;
	case "topaz":
		if (me->query("max_jing") > me->query("eff_jing") || me->query("eff_jing") > me->query("jing")
		&& random(2)==0) {
			message_vision(HIY"ֻ��$N��˫�ۿ���֮�������֣������ʱ����\n"NOR, me);
			me->add("eff_jing", 15 * socket_level);
			if (me->query("eff_jing") > me->query("max_jing"))
				me->set("eff_jing", me->query("max_jing"));
			me->add("jing", 25 * socket_level);
			if (me->query("jing") > me->query("eff_jing"))
				me->set("jing", me->query("eff_jing"));
		}
		break;
	case "sapphire":
		if (me->is_busy() && me->is_busy() <= (socket_level + 1) / 2 + 1
		&& random(3)==0) {
			message_vision(HIB"$Nֻ��һ�ɾ�����������������ȫ����������Ѩ�������ĳ������һ���ͨ��\n"NOR, me);
			me->start_busy(1);
		}
		break;
	case "emerald":
		break;
	case "amethyst":
		break;
	case "diamond":
		break;
	case "skull":
		break;
	}
	return;
}

void check_fight(object me)
{
	int i, sockets;

	if (!me || !query("equipped")) return;
	if (me->query("diablo/" + TYPE_CLOTH + "/id") != query("id")) return;
	if (living(me) && me->is_fighting()) {
		sockets = query("sockets/max");
		for (i = 1; i <= sockets; i++)
			spec_recover(me, query(sprintf("sockets/socket%d", i)),
query(sprintf("sockets/socket%d_level", i)));
	}

	call_out("check_fight", 1, me);
}
