// qiu.c �𴦻�
// By Lgg,1998.10

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "teamjob.c"
string ask_job();
void reward_dest(object obj,object ob);
void thank_dest(object obj,object ob);

void create()
{
        set_name("�𴦻�", ({"qiu chuji", "qiu"}));
        set("gender", "����");
        set("age", 36);
        set("class", "taoist");
        set("nickname",HIM"������"NOR);
        set("long",
                "�����ǽ������˳ơ������ӡ����𴦻������ˣ�����������\n"
                "�����⣬��ĿԲ����˫ü�絶����ò���ϣ�ƽ���������\n");
        set("attitude", "heroism");
        set("shen_type",1);
        set("str", 52);
        set("int", 50);
        set("con", 50);
        set("dex", 50);

        set("title","ȫ������֮��");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.jianqi" :),
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.qixinggongyue" :),
                (: perform_action, "sword.sanqing" :),

        }));

        set("qi", 18000);
        set("max_qi", 18000);
        set("jing", 33600);
        set("max_jing",33600);
        set("neili", 46000);
        set("max_neili", 46000);
        set("jiali", 100);

        set("combat_exp", 6500000);
        set("score", 300000);

        set_skill("force", 200);
        set_skill("xiantian-qigong", 350);    //��������
        set_skill("sword", 200);
set_skill("qixing-jian",280);
set_skill("qixing-shou",280);
set_skill("qixing-array",280);
        set_skill("quanzhen-jian",250);  //ȫ�潣
        set_skill("dodge", 250);
        set_skill("jinyan-gong", 300);   //���㹦
        set_skill("parry", 200);
        set_skill("haotian-zhang", 250);    //�����
        set_skill("literate",200);
        set_skill("strike",200);
        set_skill("taoism",250);
set_skill("hand", 250);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");
	set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 250);

        create_family("ȫ���", 2, "����");

        set("book_count",1);
        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
		 "job"  : (: ask_jianxi :),
		"��ҩ" : (: ask_job :),
		"yaojob" : (: ask_job :),
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("d/quanzhen/npc/obj/grayrobe")->wear();

}

void init()
{
        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, this_player());
}


void greeting(object ob)
{
        mapping fam;
        int i;
        object me;

        me = this_object();
if (!ob) return;
        if (interactive(ob) && !environment(ob)->query("no_fight"))
        {
             if (!(fam = ob->query("family")) || fam["family_name"] != "ȫ���")
 {
                if (ob->query("shen")>-5000) {
                        command("say �����Ǳ����صأ����߶�С��Щ��");
                }
                else {
                        command("say ����ħͷ�����Ҵ�����ȫ���صأ���һ��Ҫɱ���㣡");
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                }
             }
             else {
                command("smile "+ob->query("id"));
             }
        }
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("xiantian-qigong",1) < 50 ) {
                command("say ��ı����ڹ��ķ������,�������Ը�������书��");
                return;
        }
        if ((int)ob->query("shen")<5000) {
                command("say �����������ұ�ѧ���˵Ļ���Ʒ�ʣ������ܶ���Щ����֮
�£���һ������Ϊͽ��\n");
                return;
        }
        command("say �ðɣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}

string ask_job()
{
	  mapping job_stat;
	  object ob2;
	  object ob = this_player();
	  object me = this_object();

	  job_stat = ob->query_temp("qz_caiyao");

   if(this_object()->is_busy())
{
message_vision("�𴦻���$N˵����������æ���أ���\n",me);
				return "�Ȼᣡ\n";
}

	  if ( ob->query("family/family_name") != "ȫ���" )
					 return "��λ"+RANK_D->query_respect(ob)+"����ȫ��̵��ӣ�����ͷ���\n";

	  if(job_stat){
				command("hammer "+ob->query("id"));
				return "�㻹û������񣬾�����Ҫ�µģ�\n";
	  }



	  command("nod");
	  command("say �ã���������õĲ�ҩ�������ˣ���ȥɽ��������ȥ��һЩ������");
	  ob2 = new(__DIR__"obj/yaochu");
	  ob2->move(me);
	  ob->set_temp("qz_caiyao",1);
          ob->set_temp("qz/caiyao",1);
	  command("give yao chu to "+ob->query("id"));

	  return "��ȥ��أ�·��ҪС��һЩ��\n";
}

int accept_object(object me, object obj)
{
		  object ob = this_player();

		  command( "say "+obj->name()+"?");

   if(this_object()->is_busy())
{
message_vision("�𴦻���$N˵����������æ���أ���\n",me);
return 0;
}

if (userp(obj) )
{
		  command( "say ������ⶫ����ʲ�᣿" );
		  return 0;
}
if( obj->query("ownmake") )
{
		  command( "say ������ⶫ����ʲ�᣿" );
		  return 0;
}

        if( !obj->query("yaocai") )
{
		  command( "say ������ⶫ����ʲ�᣿" );
		  return 0;
}
        if( obj->query_temp("byname")!=me->query("id") )
{
		  command( "say ����������ҵ��İɣ���Ҫ���ҵ�!" );
		  return 0;
}
		  if (
				 obj->query("id") == "chuanbei" ||
				 obj->query("id") == "fuling" ||
				 obj->query("id") == "gouzhi zi" ||
				 obj->query("id") == "heshouwu" ||
				 obj->query("id") == "huanglian" ||
				 obj->query("id") == "jugeng" ||
				 obj->query("id") == "jinyin hua" ||
				 obj->query("id") == "shengdi"
			)
			{

			  if ( ob->query("family/family_name") == "ȫ���" ) {
this_object()->start_busy(2);
					 remove_call_out("reward_dest");
					 call_out("reward_dest", 0, obj, ob);
			  }
			  else {
this_object()->start_busy(2);
					 remove_call_out("thank_dest");
					 call_out("thank_dest", 0, obj, ob);
			  }

			  return 1;
		  }

		  command( "hmm" );
		  command( "say ������ⶫ����ʲ�᣿" );

		  return 0;
}

void reward_dest(object obj,object ob)
{
		  int exp;
	object yaochu = present("yao chu",this_player() );
   if(yaochu)destruct(yaochu);
	command( "pat "+ob->query("id"));
	command( "say "+ob->query("name")+"�ɵĲ�����ȥ��Ϣһ�°ɣ�\n");
	if(ob->query_temp("qz_caiyao",1) )
	{
		ob->delete_temp("qz_caiyao");
		ob->delete_temp("qz/caiyao");
		exp = 80+random(80);
		ob->add("combat_exp",exp);
		ob->add("potential",exp*2/3);
		ob->add("herb/times",1);
              message_vision( "\n$N����ˣ�\n"
                + chinese_number(exp ) + "��ʵս���飬\n"
                + chinese_number(exp*2/3) + "��Ǳ�ܣ�\n" NOR, ob);
	}
	destruct(obj);
}


void thank_dest(object obj,object ob)
{
	command( "jump");
	command( "say ���Ǻ���Ҫ��Щҩ�ģ���л����\n");
	destruct(obj);
}

