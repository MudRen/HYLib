// zhaocaifeng.c �Կ���-�÷�
// 20:47 99-1-17
#include <ansi.h>
#include <command.h>
inherit NPC;

void consider();
int do_gongzuo();
int ask_done();
void create()
{
        set_name("�Կ���", ({"zhao junrong", "zhao"}));
        set("gender", "Ů��");
        set("age", 30);
        set("long", 
                "�������ݳ��������Ĳ÷죬�����˳������¡�\n");
        set("attitude", "peaceful");             
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("qi", 100);
        set("max_qi", 100);
        set("jing", 100);
        set("max_jing", 100);
        set("neili", 120);
        set("max_neili", 120);
        set("jiali", 0);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set_skill("force", 10); 
        set_skill("unarmed", 10); 
        set_skill("dodge", 10); 
        set_skill("parry", 10);          

        set("inquiry", ([
                "����" : (: do_gongzuo :),
        ]) );

        setup();
        carry_object("clone/cloth/cloth")->wear();
}
int do_gongzuo()
{      
        object me;
        me = this_player(); 
        if (me->query("combat_exp")>=10000)
        {
               command("say ����书���Ҷ���Ҷ����Ҫ���ˣ�����С�²�������ܡ�\n");
               return 1;
         }
    if( me->query_temp("gongzuo/yunbu")>0)
    {
                tell_object(me,"��ȥ�Ѳ�ƥ�ٺú󽻸��Ұɡ�\n");
                return 1;
    }  
    message_vision(CYN"�Կ��ݶ�$N˵���������ٺõĲ�ƥ�������ˣ���͵�����Ŀⷿ��ȥ��Щ������\n"NOR,me); 
        me->set_temp("gongzuo/yunbu", 1);
        return 1;   
}
int accept_object(object me, object ob)
{
        object ob1;
        if (strsrch(ob->query("name"), "�ٺõĲ�") < 0) 
        {
            command("say ������������������ٺõĲ���\n");
        }
        else if (me->query_temp("gongzuo/yunbu")<1)
        {
         command("say ��û�н�������ٲ�ѽ��\n");
        }
        else
        {
    message_vision(CYN"�Կ��ݶ�$N˵���������ˣ�������Ĺ�Ǯ��\n"NOR,me);
    message_vision(CYN"�Կ��ݵݸ�$NһЩͭǮ��\n"NOR,me);  
                me->delete_temp("gongzuo/yunbu");
                me->add("combat_exp",20+random(20));
                me->add("potential",10+random(10));
                ob1=new("/clone/money/silver");
                ob1->move(me); 
    call_out("destroying", 1, this_object(), ob);
            return 1;
        }
    return 0;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

