// huangboliu.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

#include <ansi.h>;
int do_gongzuo();
int ask_done();
mapping *changxi = ({ 
         ([ "changxi":"����","where":"baituo"   ]),
         ([ "changxi":"��ü","where":"emei"  ]),
         ([ "changxi":"��ɽ","where":"hengshan"   ]),   
         ([ "changxi":"��Ĺ","where":"gumu" ]),   
         ([ "changxi":"��ɽ","where":"henshan"]),   
         ([ "changxi":"��ɽ","where":"xx"]),   
         ([ "changxi":"����","where":"lingjiu"]),   
         ([ "changxi":"����","where":"mingjiao"]),   
         ([ "changxi":"ȫ��","where":"quanzhen"]),   
         ([ "changxi":"����","where":"shaolin"]),   
         ([ "changxi":"������","where":"tianlongsi"]),   
         ([ "changxi":"�䵱","where":"wudang"]),   
         ([ "changxi":"��ң","where":"xiaoyao"]),   
         ([ "changxi":"���޺�","where":"xingxiuhai"]),   
         ([ "changxi":"̩ɽ","where":"taishan"]),   
         ([ "changxi":"ѩɽ��","where":"xueshan"]),   
         ([ "changxi":"Ľ������","where":"mr"]),   
         ([ "changxi":"������","where":"tiezhang"]),            
         ([ "changxi":"������","where":"lingxiao"]),            
         ([ "changxi":"����ɽ","where":"kunlun"]),            
         ([ "changxi":"�嶾��","where":"wudujiao"]),            
                   });
mapping query_changxi()
{
        return changxi[random(sizeof(changxi))];
}

void create()
{
	set_name("�Ʋ���", ({ "huang boliu","huang","boliu"}) );
	set("gender", "����" );
	set("title", HIB"������̷���������"NOR);
	set("nickname", HIW"������"NOR);
	set("age", 85);
	set("long", "һ�����룬ֱ�����أ���Ŀ���֮����\n");
	set("attitude", "friendly");
	set("shen_type", 1);

	set("per", 21);
	set("str", 53);
	set("int", 53);
	set("con", 52);
	set("dex", 50);

	set("max_qi", 10000);
	set("max_jing",10000);
	set("neili", 50000);
	set("max_neili", 50000);
	set("combat_exp", 2000000);
	set("jiali", 100);
	set("score", 30000);

          set_skill("sword", 200);
          set_skill("parry", 200);
        set_skill("literate",200);
          set_skill("dodge", 200);
          set_skill("unarmed", 200);
          set_skill("whip", 200);
          set_skill("force", 200);
        set_skill("staff", 200);
          set_skill("strike",200);
         set_skill("blade", 200);

         set_skill("tmjian", 200);
         set_skill("tmzhang", 200);
         set_skill("tmdao", 250);
         set_skill("pmshenfa", 200);
         set_skill("tmdafa", 200);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.moxiao" :),
                (: perform_action, "blade.moxiao" :),
                (: perform_action, "unarmed.huashen" :),                
                (: perform_action, "unarmed.tmduan" :),                
        }) );

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 800);
        set("inquiry", ([
                "��˵����" : (: do_gongzuo :),
                "work"  : (: do_gongzuo :),
                "done" : (: ask_done    :),
                "���" : (: ask_done    :),
                "����" : (: ask_done    :),
	]) );

	create_family("�������",2,"���� ����������");

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
         if (ob->query_int() < 20) {
              command("say " + RANK_D->query_respect(ob) +
                        "�߿��߿����Ҳ����ɵ��˵����");
                return;
        }
         if (ob->query_dex() < 20) {
                command("say " + RANK_D->query_respect(ob) +
                        "���ֲ��ݣ����������ʦ�ɡ�");
                return;
        }
        if ((int)ob->query("shen") > -10000) {
                command("say " + RANK_D->query_respect(ob) +
                        "�㻹�����ĺ��������һ��������㡣");
                return;
        }
        command("say ������ ���Ҿ�������ɡ�");
        command("recruit " + ob->query("id"));
}


int do_gongzuo()
{      
        mapping changxi,changxiwhere;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("ryjob2/changxi")>0)
    {
                tell_object(me,HIW"���ȥ���ʥ�̰ɣ�\n"NOR);
                return 1;
    } 
        if ((int)me->query_condition("ry2_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵�����Ҫ������,�Ȼ�����!\n", this_object(), me);
                      return 1;
            }

        if( me->query("family/family_name") != "�������")
           {
                      message_vision("$N����$n˵���������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }

    changxi = this_object()->query_changxi();
    changxiwhere = changxi["where"];
    message_vision(HIC"�Ʋ�����$N˵������ȥ" + changxi["changxi"] + "ȥ�����ʥ�̣�����ʥ��֮����\n"NOR,me); 
        me->set_temp("ryjob2/changxi", 1);
        me->set_temp("ryjob2/where",changxiwhere);
        me->set_temp("ryjob2/cx",changxi["changxi"]);

me->apply_condition("ry2_busy", 2);
        ob=new(__DIR__ "ling");
        ob->move(me);
    message_vision(HIC"�Ʋ�����$N˵������Щ��������ȥ����˵(youshuo)�ðɡ�\n"NOR,me); 
        return 1;   
}

int ask_done()
{      

        object me,ob;
int exp,pot;
exp=80+random(60);
pot=60+random(45);

        me = this_player(); 
        
        if( me->query("family/family_name") != "�������")
           {
                      message_vision("$N����$n˵���������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }
  
    if( me->query_temp("ryjob2/changxi")< 1)
    {
                tell_object(me,CYN"��û�����𣿡�\n"NOR);
                return 1;
    } 

    if( me->query_temp("ryjob2/done")< 1)
    {
                tell_object(me,HIW"����˵������˵��Ŀ�Ļ�û�дﵽ����ȥ��˵�ɡ�\n"NOR);
                return 1;
    }
    message_vision(HIG"�Ʋ�����$N˵�������ò����������ʥ�̡�\n"NOR,me); 
    me->add("combat_exp",exp);
    me->add("potential",pot);
        me->delete_temp("ryjob");
    me->delete_temp("ryjob2");
	   tell_object(me,HIW"�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);

    return 1;
}