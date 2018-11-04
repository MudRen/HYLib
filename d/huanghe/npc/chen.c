// chen.c
inherit NPC;
#include <ansi.h>;
#include <skill.h>
#include <weapon.h>
#include <combat.h>
void create()
{
        set_name( "������" ,({ "chen xuanfeng", "chen" }));
        set("title", "�ڷ�˫ɷ");
        set("nickname", HIY"ͭʬ"NOR);
        set("gender", "����");
        set("age", 35);
        set("long",
            "�����ǻ�ҩʦ�Ķ����ӣ���Ũü���ۣ���������������׳����ֻ��\n"
            "��ɫ΢΢���ơ�\n");
        set("attitude", "aggressive");
        set("str", 27);
        set("int", 32);
        set("con", 35);
        set("max_qi",5500);
        set("max_jing",5000);
        set("neili", 5500);
        set("max_neili", 25500);
        set("jiali", 100);
        set("shen",-50000);

        set("combat_exp", 1500000);

        set_skill("claw", 180);
        set_skill("force", 180);
        set_skill("parry", 180);
        set_skill("dodge", 140);
        set_skill("jiuyin-baiguzhao", 280);
        set_skill("bibo-shengong", 280);
        set_skill("anying-fuxiang", 280);

        map_skill("force", "bibo-shengong");
        map_skill("parry", "luoying-shenjian");
        map_skill("dodge", "anying-fuxiang");
        map_skill("claw", "jiuyin-baiguzhao");
        prepare_skill("claw", "jiuyin-baiguzhao");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "claw.zhua" :),
                (: perform_action, "claw.cuijin" :),
                (: perform_action, "claw.zhua" :),
        }) );

        create_family("�һ���", 2, "�������");
        set("inquiry", ([
           "ͭʬ":     "�����ϵ��˶���ô���ҵģ����²��£�����������",
           "��а":     "������ʦ���Ĵºš�",
           "����":     "�������ʦ�����ĸ���֮һ���Ǹ��϶��ס�ڰ���ɽ��",
           "�ϵ�":     "����ү�ѳ��ҵ�����ȥ�ˣ�������һ�ơ�",
           "��ؤ":     "��ؤͳ����ԭ��ؤ�������Ϊǿ��",
           "���߹�":   "���߹��书��ǿ�����ҽ̻������С������ʮ���ƣ��ɺޣ�",
           "����":     "������ʦ���Ķ�Ů�����ǵ������ԡ�",
           "÷����":   "�����ҵ�ʦ�ã�Ҳ���ҵ����ҡ�",
           "������":   "��������ô�����ǰ׳հ���",
           "��ҩʦ":   "������ʦ����"]) );
        setup();
        carry_object("/kungfu/class/taohua/obj/bupao")->wear();
}

void kill_ob(object me)
{
	object ob = this_object();
	if (environment(ob)->query("short") == "ʯ��" && !objectp(present("mei chaofeng", environment(ob)))) {
		command("say �����ҵľ����澭��û��ô���ף�");
		message_vision(HIY"���������㼱�����У���·������ȥ��"NOR, me);
	        ob->add_temp("apply/attack", 200);
	        ob->add_temp("apply/damage", 200);
		COMBAT_D->do_attack(ob,me, ob->query_temp("weapon"));
		COMBAT_D->do_attack(ob,me, ob->query_temp("weapon"));
		COMBAT_D->do_attack(ob,me, ob->query_temp("weapon"));
	        ob->add_temp("apply/attack", -200);
		ob->add_temp("apply/damage", -200);
		command("out");
		this_object()->set_temp("target", me->query("id"));
                this_object()->move("/d/huanghe/shamo1");
	}
        ::kill_ob(me);
}

void die()
{
	object ob = this_object(), me, obj;
	if (!ob->query_temp("target")) {
	        call_out("do_die", 1, ob);
		return;
	}
	if (environment(ob)->query("short") != "ɳĮ"){
	        call_out("do_die", 1, ob);
		return;
	}
	me = ob->query_temp("last_damage_from");
	if (me->query("id") != ob->query_temp("target")) {
		ob->revive(1);
		command("say �ã���Ȼ����" + me->name(1) + "���㣬�ߣ�");
		message_vision(HIY"����������Ʋ��ã�ת�����ˣ�\n"NOR, me);
		destruct(ob);
		return;
	}
	ob->delete_temp("target");
	if (me->query("jiuyin/full") || present("jiuyin xiajuan", me) || (!me->query("jiuyin/xia") && me->query("jiuyin/xia-failed") > 2)) {
	        call_out("do_die", 1, ob);
		return;
	}
	if (me->query("jiuyin/xia") && !present("jiuyin xiajuan", me)) {
		obj = new ("/clone/book/jiuyin-xia");
		obj->move(me);
		message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+me->query("name")+"�õ������澭�¾�����\n"NOR, users());
	        call_out("do_die", 1, ob);
		return;
	}
	message_vision(HIW"$N��������ʬ��ĸ������˵㶫����\n"NOR, me);
	if (me->query("kar") > 40 && random(20) == 0) {
		if(present("bishou", me)) {
			message_vision(HIW"˳�ֳ��ذ�׸���һС��Ƥ������ϸһ�������Ǿ����澭�¾�\n"NOR, me);
			obj = new ("/clone/book/jiuyin-xia");
			obj->move(me);
			message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+me->query("name")+"�õ������澭�¾�����\n"NOR, users());
			me->delete("jiuyin/xia-failed");
			me->set("jiuyin/xia", 1);
		} else {
			message_vision(HIW"��ϧ$Nû�д���ذ�ף�ֻ����ʱ���ա�\n"NOR, me);
			me->add("jiuyin/xia-failed", 1);
		}
	} else {
		message_vision(HIW"��ϧ$N��û���⡣\n"NOR, me);
		me->add("jiuyin/xia-failed", 1);
	}
	call_out("do_die", 1, ob);
	return;
}

void do_die(object ob)
{
        :: die();
}
