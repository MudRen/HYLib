//������100�����II
// xiaoer.c ƽ���ǵ�С��
//����lywin 2000/6/1 ��ͯ��

#include <ansi.h>
#include <command.h>
inherit NPC;

void consider();
int do_gongzuo();
int ask_done();
void create()
{
        set_name("��ʦ��", ({"shifu", "fu"}));
        set("gender", "����");
        set("age", 45);
        set("long", 
                "����С�Ե�����˴�ʦ����\n");
        set("qi", 100);
        set("max_qi", 100);
        set("jing", 100);
        set("max_jing", 100);
        set("per", 25);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set("inquiry", ([
                "����" : (: do_gongzuo :),
                "job"  : (: do_gongzuo :),
                "work" : (: do_gongzuo :),
        ]) );

        setup();
        carry_object("clone/cloth/cloth")->wear();
}
int do_gongzuo()
{      
        object me;
        me = this_player(); 
        
    if (me->query("combat_exp")>=30000)
    {
                tell_object(me,"���С����ô�������Ĵ�ݡ�\n");
                return 1;
    }  
    if( me->query_temp("gongzuo/zuocai")>0)
    {
                tell_object(me,"��ȥ���˰ɡ�\n");
                return 1;
    }  
    message_vision(CYN"��ʦ����$N˵�����⼸����˶࣡��������������������˰ɡ�\n"NOR,me); 
        me->set_temp("gongzuo/zuocai", 1);
        return 1;   
}
int accept_object(object me, object ob)
{
        object ob1;
        if (me->query_temp("gongzuo/zuocai")<1)
        {
         command("say ��û������Ҫ�������ɡ�\n");
        }
        else if ( ob->query("name") != "���õĲ�" )
//        else if (strsrch(ob->query("name"), "���õĲ�") < 0) 
        {
            command("say �������õĲˣ��㲻�ǿ���Ц�ɣ�\n");
        }
        else
        {
    message_vision(CYN"��ʦ����$N˵���������ˣ�������Ĺ�Ǯ��\n"NOR,me);
    message_vision(CYN"��ʦ���ݸ�$NһЩ���ӡ�\n"NOR,me);  
                me->delete_temp("gongzuo/zuocai");
                me->delete_temp("gongzuo/zuocai");
                if (me->query("combat_exp")>=15000)
                {
                  me->add("combat_exp",2);
                  me->add("potential",1);
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
                  call_out("destroying", 1, this_object(), ob);
                }
                else if (me->query("combat_exp")< 15000)
                {
                me->add("combat_exp",50+random(10));
                me->add("potential",30+random(10));
                ob1=new("/clone/money/silver");
                ob1->move(me); 
                ob1=new("/clone/money/silver");
                ob1->move(me); 
                call_out("destroying", 1, this_object(), ob);
                }
            return 1;
        }
    return 0;
}

void destroying(object me, object obj)
{
//        destruct(obj);
        return;
}
