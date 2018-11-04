// jiuyin2.c �����澭�¾�

inherit ITEM;

int do_study(string arg);

void create()
{
	set_name("�����澭�¾�", ({ "jiuyin xiajuan", "jiuyin", "xiajuan", "renpi"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����Ƥ�����������ѧ�ؼ��������澭�����¾������Ķ�ֻ��ʵս�е���ʽ���ţ�ȴ�����ķ��Ϳھ�����һҳ��д�ţ���֮����������������㣬�ǹ���ʤʵ������ʤ���ࡣ�ഫ���λ������һλ�л��ѵ�������\n");
		set("value", 40000);
		set("material", "leather");
		set("no_drop", "��ô���������ؼ�����ɲ������ⶪ����\n");
		set("no_get", "�������������˵ı�������˯����Ҫ����ͷ�棬���޷���ȡ��\n");
	}
}

void init()
{
	add_action("do_study", "du");
	add_action("do_study", "study");
}

int do_study(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	int i, level, *levels = ({0,0,0,0}), *can = ({0,0,0,0}); 
	int cost, neili_lost, neili_adjust;

	if (!(arg=="jiuyin xiajuan" || arg == "jiuyin" || arg == "xiajuan" || arg == "renpi"))
		return 0;

	if (where->query("pigging")){
		write("�㻹��ר�Ĺ���ɣ�\n");
		return 1;
        }
	if (me->is_busy()) {
		write("��������æ���ء�\n");
		return 1;
	}

	if( me->is_fighting() ) {
		write("���޷���ս����ר�������ж���֪��\n");
		return 1;
	}

/*        if(!arg || !objectp(ob = present(arg, me)) ){
                write("��Ҫ��ʲô��\n");
                return 1;
        }
*/
	if (!id(arg)) {	
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	if( !me->query_skill("literate", 1) ){
		write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
		return 1;
	}

	cost = 30 + 30 * (25 - me->query("int"))/20;
	if (cost < 10) cost = 10; // minimum cost

	if (arg == "jiuyin" && present("jiuyin shangjuan", me)) {
		if (!random(5)) message("vision", me->name() + "ר����־������һ��������һ����Ƥ�����о��š�\n", environment(me), me);
		if( (int)me->query("jing") < cost * 5 ) {
			write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
			return 1;
		}

		neili_adjust = 0;
		levels[ 0 ] = me->query_skill("force", 1);
		levels[ 1 ] = me->query_skill("dodge", 1);
		levels[ 2 ] = me->query_skill("parry", 1);
		levels[ 3 ] = me->query_skill("sword", 1);
		for (i = 0; i < 4; i++)
		{
			if (levels[i] > 80) neili_lost = 15;
			else if (levels[i] > 60) neili_lost = 10;
			else neili_lost = 5;

			if ((int)me->query("neili") + neili_adjust >= neili_lost) {
				neili_adjust -= neili_lost;
				can[i] = 1;
			}
			if (can[i] > 0 && (int)me->query("combat_exp") < (int)levels[i]*levels[i]*levels[i]/10) {
				neili_adjust += neili_lost;
				can[i] = -1;
			}
			if (can[i] > 0 && levels[i] > 99) {
				neili_adjust += neili_lost;
				can[i] = -2;
			}
		}
		if (can[0] <= 0 && can[1] <= 0 && can[2] <= 0 && can[3] <= 0) {
			if (can[0] == -2 && can[1] == -2 && can[2] == -2 && can[3] == -2) {
				write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
				return 1;
			}
			else {
				write("��������Լ�ʵս���鲻�����޷�������ô������书��\n");
				return 1;
			}
		}

		me->add("neili", neili_adjust);
		write("���ж��������澭��������ѧ����ʶ������һ�㡣\n");
		if (can[0]) {
			me->receive_damage("jing", cost + 5);
			if(!levels[0]) me->set_skill("force", 0);
			me->improve_skill("force", (int)me->query_skill("literate", 1)/4+1);
		}
		if (can[1]) {
			me->receive_damage("jing", cost + 3);
			if(!levels[1]) me->set_skill("dodge", 0);
			me->improve_skill("dodge", (int)me->query_skill("literate", 1)/5+1);
		}
		if (can[2]) {
			me->receive_damage("jing", cost);
			if(!levels[2]) me->set_skill("parry", 0);
			me->improve_skill("parry", (int)me->query_skill("literate", 1)/5+1);
		}
		if (can[3]) {
			me->receive_damage("jing", cost + 2);
			if(!levels[3]) me->set_skill("sword", 0);
			me->improve_skill("sword", (int)me->query_skill("literate", 1)/5+1);
		}
        }
	else {
		if (!random(5)) message("vision", me->name() + "ר����־���о�һ����Ƥ��\n", environment(me), me);
		if( (int)me->query("jing") < cost ) {
			write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
			return 1;
		}

		level = me->query_skill("taoism", 1);
		if (level > 80) neili_lost = 15;
		else if (level > 60) neili_lost = 10;
		else neili_lost = 5;

		if ((int)me->query("neili") < neili_lost) {
			write("�������������޷�������ô����ĵ�ѧ��\n");
			return 1;
		}

		if (level > 99) {
			write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
			return 1;
		}

		me->receive_damage("jing", cost);
		me->add("neili", -neili_lost);
		if(!level) me->set_skill("taoism", 0);
		write("���ж��������澭���¾�������һЩ��ѧ֪ʶ��\n");
		me->improve_skill("taoism", (int)me->query_skill("literate", 1)/4+1);
	}
	return 1;
}
