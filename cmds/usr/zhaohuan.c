// �ٻ���� (by xbd)

#include <ansi.h>

inherit SKILL;

string *ns = ({	"force",
		"dodge",
		"parry",
		"unarmed",
		"strike",
		"cuff",
		"finger",
		"claw",
		"hand",
		"leg",
		"sword",
		"blade",
		"whip",
		"hammer",
		"staff",
		"axe",
		"throwing",	
		"literate",
		"shenzhao-jing",
});

object clone_guard(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	int load = 0;


	if (!me->query("guard/flag"))
		return notify_fail("ƾ�����ڵ���������û���ʸ�ӵ������أ�\n");
	
	if (!me->query("guard/active"))
		return notify_fail("�����ڻ�û���չ���ӣ������Ҫ�Ļ������Ե�������ʿ����ȥҪһ����\n");

    if(me->query_condition("killer"))
        return notify_fail("ͨ���У�����Ȩʹ�á�\n");

    if(me->is_busy())
        return notify_fail("��������æ��\n");
	if (me->query("neili") < 1000)
		return notify_fail("�������̫���ˣ��޷�������Х��\n");

	if (me->query("jing") < 100)
		return notify_fail("��ľ���̫���ˣ��޷�������Х��\n");
if (me->query("last_alert") > me->query("mud_age") ) 
{
		me->set("last_alert", me->query("mud_age"));
}
	if (!objectp(ob = me->query_temp("guard_ob"))) {
		if (!wizardp(me) && me->query("last_alert")
&& (me->query("mud_age") - me->query("last_alert")) < 900)
			return notify_fail(sprintf("����ٻ������������ٹ�%d����ܼ����ٻ���\n",
900 + me->query("last_alert") - me->query("mud_age")));
		if (!objectp(ob = clone_guard(me)))
			return notify_fail("����ļ������޸��У����Ժ�\n");
		load = 1;
		me->set("last_alert", me->query("mud_age"));
		me->set_temp("guard_ob", ob);
	}
	else if (environment(me) == environment(ob))
		return notify_fail("�����������������\n");
	else if (!living(ob))
		return notify_fail("����Ŀǰ��״̬����ô��������������أ�\n");
	else if (ob->is_busy())
		return notify_fail("����æ�ţ��޷���������ٻ���\n");
        else if (!environment(ob))
		return notify_fail("����Ŀǰ��״̬����ô��������������أ�\n");

	me->add("neili", -500);
	me->add("jing", -50);
me->start_busy(3);	
	message_vision(HIM"$N������Х��Х�����ߺ��ͣ��ƺ����ڴ�ʲô���š�\n"NOR, me);
	if (!load) message("vision", HIG + ob->name() + "�ƺ�������" + me->name() + "�ĺ������Ҵҵ���ȥ�ˡ�\n"NOR, environment(ob));
	ob->move(environment(me));
	ob->set_leader(me);
	message_vision(HIG"$N��������һ��Х����$P�໥��Ӧ��ֻת�ۼ�$n������$N����ߡ�\n"NOR, me, ob);
	write(HIW"�����ڿ���ָ�"NOR"
"HIW"set_name <����> \tΪ��������
set_long <����> \t�޸���������
set_title <�ƺ�> \t�޸����ĳƺ�
ticks \t\t\t�鿴ս��ָ������
      [1-5 <ָ��>] \t����ս��ָ��
      [-d 1-5|all] \tɾ��ս��ָ��
ע��һ���趨��ָ�����У�Ԥ���ս��ģʽ����������
att <ĳ��> \t\t����ĳ��
sha <ĳ��> \t\tɱ��ĳ��
ting \t\t\tֹͣս��
heji <ĳ��> \t\t�ϻ�ĳ��
order [un]accept object �趨[��]������Ʒ
      [un]accept fight \t�趨[��]���ܱ���
      <ָ��> \t\t�´�ս��ָ��
control <����> \t\t������ͨң��ִ��ĳָ��
set save_me <�ٷֱ�> \t������ѪС�ڶ��������Զ�����
hulian <����> \t\t����ĳ�书
taolun <����> \t\t����ĳ�书
lianxi <����> \t\tָ��ĳ�书
mache <�ص�> \t\t����ȥĳ��
shape <ID> \t\t\t��״̬\n"NOR);
		
	return 1;

}

object clone_guard(object me)
{
	object ob, weapon;
	mapping status;
	string *ks;
	int i, n;

	if (me->query("guard/gender") == "girl")
		ob = new("/clone/guard/long2");
	else
		ob = new("/clone/guard/baoer");
	if (!ob) return ob;

	status = me->query("guard/status");
	if (mapp(status)) {
		ks = keys(status);
		for (i = 0; i < sizeof(status); i++)
			ob->set(ks[i], status[ks[i]]);
	}
	if (me->query("guard/gender") == "girl") {
		ob->set("id", me->query("id") + "'s shinu");
		if (!(stringp(me->query("guard/name"))))
			ob->set_name(me->name() + "����Ů", ({me->query("id") + "'s shinu","shi nu"}) );
		else
			ob->set_name(me->query("guard/name"), ({me->query("id") + "'s shinu","shi nu"}) );
	} else {
		ob->set("id", me->query("id") + "'s shitong");
		if (!(stringp(me->query("guard/name"))))
			ob->set_name(me->name() + "����ͯ", ({me->query("id") + "'s shitong", "shi tong"}) );
		else
			ob->set_name(me->query("guard/name"), ({me->query("id") + "'s shitong", "shi tong"}) );
	}
	if (stringp(me->query("guard/long")))
		ob->set("long", me->query("guard/long"));
	if (stringp(me->query("guard/title")))
		ob->set("title", me->query("guard/title"));
	ob->set("possessed", me);
	ob->set("host_id", me->query("id"));
	ob->set("marry", me->query("id"));
	ob->set("couple/have_couple", 1);
	ob->set("couple/couple_name", me->name());
	ob->set("baohu", me->query("id"));

	ob->set("double_attack", me->query("double_attack"));
	ob->set("szj", me->query("szj"));

	ob->set("str", (me->query("str") > 50 ? 50 : me->query("str")));
	ob->set("int", (me->query("int") > 50 ? 50 : me->query("int")));
	ob->set("con", (me->query("con") > 50 ? 50 : me->query("con")));
	ob->set("dex", (me->query("dex") > 50 ? 50 : me->query("dex")));
	ob->set("kar", (me->query("kar") > 50 ? 50 : me->query("kar")));
//	ob->set("per", (me->query("per") > 50 ? 50 : me->query("per")));

	ob->set("combat_exp", (int)me->query("combat_exp") * 3 / 4);

	for (n = 0; n < 1000; n++)
		if (n*n*n/10 >= ob->query("combat_exp"))
			break;
	ob->set_skills(me->query("guard/skills"));
if (n <10) n=10;
	for (i = 0; i < sizeof(ns); i++)
		ob->set_skill(ns[i], n);
	if (!me->query_skill("literate", 1))
		ob->delete_skill("literate");
	else
		ob->set_skill("literate", me->query_skill("literate", 1));
	if (!me->query_skill("shenzhao-jing", 1))
		ob->delete_skill("shenzhao-jing");

	ob->set_learned(me->query("guard/learned"));
	ob->set_skill_map(me->query("guard/skill_map"));
	ob->set_skill_prepare(me->query("guard/skill_prepare"));

	ob->set("max_neili", (int)ob->query_skill("force") * 15);
	ob->set("neili", ob->query("max_neili"));
	ob->set("max_qi", (int)ob->query_skill("force") * 20);
	ob->set("eff_qi", ob->query("max_qi"));
	ob->set("qi", ob->query("max_qi"));
	ob->set("max_jing", (int)ob->query_skill("force") * 5);
	ob->set("eff_jing", ob->query("max_jing"));
	ob->set("jing", ob->query("max_jing"));
	ob->set("food", (ob->query("str") + 10) * 10);
	ob->set("water", (ob->query("str") + 10) * 10);
	
	if ((i = ob->query("combat_exp")) > 2000000)
		i = 200 + (i - 2000000) / 15000;
	else
		i = 200;
	ob->add_temp("apply/damage", i);
	ob->add_temp("apply/armor", i);
	
	if (ob->query("no_weapon"))
		i = 1;
	else
		i = 0;
	if (stringp(ob->query_skill_mapped("sword"))) {
		weapon = new("/clone/weapon/gangjian");
		weapon->move(ob);
		if (!i) weapon->wield();
		i = 1;
	}
	if (stringp(ob->query_skill_mapped("blade"))) {
		weapon = new("/clone/weapon/gangdao");
		weapon->move(ob);
		if (!i) weapon->wield();
		i = 1;
	}
	if (stringp(ob->query_skill_mapped("whip"))) {
		weapon = new("/clone/weapon/changbian");
		weapon->move(ob);
		if (!i) weapon->wield();
		i = 1;
	}
	if (stringp(ob->query_skill_mapped("hammer"))) {
		weapon = new("/clone/weapon/hammer");
		weapon->move(ob);
		if (!i) weapon->wield();
		i = 1;
	}
	if (stringp(ob->query_skill_mapped("staff"))) {
		weapon = new("/clone/weapon/gangzhang");
		weapon->move(ob);
		if (!i) weapon->wield();
		i = 1;
	}
	if (stringp(ob->query_skill_mapped("axe"))) {
		weapon = new("/clone/weapon/axe");
		weapon->move(ob);
		if (!i) weapon->wield();
		i = 1;
	}

	ob->change_combat_mode(me, ob->query("combat_mode"));

	return ob;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : zhaohuan
 
���ָ����������ٻ������ӡ�
 
HELP
    );
    return 1;
}
