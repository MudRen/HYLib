 // by Xiaoyao

inherit NPC;
#include <ansi.h>
void destroying(object, object);

void create()
{
        set_name("����", ({ "ding dian", "ding" }));
        set("long", "����������ף�ͷ��������ֱ���������������ò�������ֱ��ͬ��ɽ�е�Ұ�ˡ�\n");
        set("gender", "����");
        set("age", 35);
        set("unique", 1);
set("no_get",1);
        set_skill("unarmed", 520);
        set_skill("dodge", 520);
        set_skill("parry", 530);
        set_skill("force", 550);
	set_skill("taixuan-gong", 850);
        set_skill("shenzhao-jing", 380);
        map_skill("dodge","taixuan-gong");
        map_skill("force","taixuan-gong");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed","taixuan-gong");
        set("max_neili",80000);
        set("neili",80000);
        set("max_qi",36800);
        set("max_jing",36800);
        set("jing",36800);
        set("qi",36800);
        set("eff_jingli",38000);
        set("jingli",38000);
        set("jiali",100);
	set("szj/passed", 1);
	set("szj/over200", 1);
	set("book_count", 1);
	set("chat_chance_combat", 80);
       set("chat_msg_combat", ({
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);
        set("combat_exp", 9900000);
        set("shen_type", 1);
        setup();
        carry_object("/clone/armor/cloth")->wear();
}

int accept_object(object me, object obj)
{
        if ((string)obj->query("id")=="lu juhua") {
        message("vision",me->name()+"������һ���̾ջ���\n",environment(me),
            ({me}));
        if(!this_object()->query("book_count")) {
		command("say ���Ѿ����˸�˪���ӻ��ˣ�����������ˡ�");
		return 0;
	}
	if (present("shenzhao jing", me)) {
		command("say �����ϲ����������վ���");
		return 0;
	}
        command("touch "+me->query("id"));
        command("say ��λ"+RANK_D->query_respect(me)+"��˪���������ӻ��İ�,�ˣ����ǿ��ǿ�����ԧ�졣");

	if (!present("shenzhao jing", me)) {
		if (me->query("szj/passed")) {
		        new("/clone/book/shenzhao-jing")->move(me);
	        	message_vision("$n�ݸ�$Nһ�����վ���\n", me, this_object() );
		        command("say ��λ"+RANK_D->query_respect(me)+"����̫��л����,�Ȿ�ڹ��ķ�ϣ�����ܺú���ϧ��");
			this_object()->set("book_count", 0);
		} else if ((int)me->query("szj/failed") < 4 && me->query("kar") > 40 && !random(30)) {
		        new("/clone/book/shenzhao-jing")->move(me);
	        	message_vision("$n�ݸ�$Nһ�����վ���\n", me, this_object() );
		        command("say ��λ"+RANK_D->query_respect(me)+"����̫��л����,�Ȿ�ڹ��ķ�ϣ�����ܺú���ϧ��");
			this_object()->set("book_count", 0);
			me->delete("szj/failed");
			me->set("szj/passed", 1);
		} else {
			command("sigh "+me->query("id"));
			command("say �����޳��ʵ��ûʲô���Ը�����ˡ�");
			if (me->query("szj/failed") < 5)
				me->add("szj/failed", 1);
		}
	}
        remove_call_out("destroying");
        call_out("destroying", 1, this_object(), obj);
        return 1;
        }
        return 0;
}

void destroying(object me,object obj)
{
        destruct(obj);
        return;
}
