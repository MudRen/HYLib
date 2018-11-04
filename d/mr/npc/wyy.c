//wang.c

inherit NPC;

void create()
{
	set_name("������", ({ "wang yuyan", "wang" }));
	set("long", "�����ü�Ϊ��ò,һ˫�۾���������.\n");
	set("nickname", "�����޲�֪");
	set("gender", "Ů��");
	set("age", 20);
	set("attitude","friendly");
	set("str", 10);
	set("dex", 30);
	set("con", 30);
	set("int", 30);
	set("per", 35);

	set("max_qi", 500);
	set("max_jing", 500);
	set("max_neili", 0);
        set("no_get", 1);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("lingwu","ask");
}

int lingwu(string arg)
{
	object me=this_player(), ob = this_object();
	string special;
	int bl, sl;
	string name;

        if (!me) return 0;
        if (!arg) return 0;
	if (!sscanf(arg, "%s about %s", name, arg)) return 0;
	if (!id(name)) return 0;

	if (!me->query("luohan_winner")) return notify_fail("�㼶�𲻹��������ڴ�����\n");
	write("����"+name()+"��̹��ڡ�" + to_chinese(arg) + "�������ʡ�\n");
	if (!(special=me->query_skill_mapped(arg))) {
		if (arg == to_chinese(arg))
			write(name()+"˵������" + arg + "����ʲô�书����ô��û��˵����\n");
		else
			write(name()+"˵������ֻ�ܴ�������⼼���и���ָ�㡣\n");
		return 1;
	}
	if (me->is_busy() || me->is_fighting()) {
		write(name()+"˵��������æ���ء�\n");
		return 1;
	}
	if (!me->query_skill(arg,1)) {
		write(name()+"˵�����㲻�����ּ��ܡ�");
		return 1;
	}
	if( arg == "force") {
		write(name()+"˵�����Ҳ���ָ����Ļ����ڹ���\n");
		return 1;
	}


	if((int)me->query("potential") < 200 ) {
		write(name()+"˵�������Ǳ��̫���ˡ�\n");
		return 1;
	}
	if((int)me->query("potential") - (int)me->query("learned_points") < 200 ) {
		write(name()+"˵�������Ǳ��̫���ˡ�\n");
		return 1;
	}

	bl=me->query_skill(arg,1);
	if (bl > me->query("jing") || me->query("jing")*100/me->query("max_jing") < 50) {
		me->receive_damage("jing",bl/5);
		write(name()+"˵����" + RANK_D->query_respect(me) + "����Ϣһ�°ɡ�\n");
		return 1;
	}
	sl=me->query_skill(special,1);
	if (bl > sl) {
		write(name()+"˵����" + RANK_D->query_respect(me)
		+ "��"+to_chinese(special)+"���費�����Ҳ���ָ�������һ���"+to_chinese(arg)+"��\n");
		return 1;
	}
	write("������" + name() + "��ָ�㣬��"+to_chinese(arg)+"�����������һ�㡣\n");
           if ((int)me->query("combat_exp",1) >850000){
               me->receive_damage("jing",bl/5*3);
	if(me->query("combat_exp") > 1000000 ) {
        me->add("potential", -random(3));
        }
                 me->improve_skill(arg, me->query_int()*3/2);
	return 1;
          }
	me->receive_damage("jing",bl/5*2);
	if(me->query("combat_exp") > 1000000 ) {
        me->add("potential", -random(3));
        }
     me->improve_skill(arg, me->query_int()*3/2);
	return 1;
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
        command("peace " + ob->query("id"));
}