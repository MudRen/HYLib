// huogongdaoren.c �𹤵���
// by mask 1999/11
inherit NPC;

#include <ansi.h>;
int ask_me() ;
void create()
{
        set_name("�𹤵���", ({ "daoren" }));
        
        set("long", 
                "������һ���곤�ĳ����ˡ�\n");
        set("gender", "����");
        set("age", 25);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 15);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 15);
        set("combat_exp", 100000);
        set("score", 20000);
        set("inquiry", ([
             "����" : (: ask_me() :),
             "work" : (: ask_me() :),
        ])); 
        set("count",10); 
        setup();
}


int ask_me()
 {
 object me;
 mapping myfam;
 me=this_player();
        
 myfam = (mapping)me->query("family");

 if ((!myfam || myfam["family_name"] != "�䵱��"))
 return notify_fail("���˶���˵�������������䵱�ɵ��£�����θɣ���\n");

 if (query("count")<1)
 return notify_fail("����˵����������ûʲô���ˣ������������ɡ���\n");

 if (!me->query_temp("questd"))
 {
 tell_object(me,"���˶���˵������ȥ�˵���ժ��˻������ҡ���\n"); 
 add("count",-1);
 me->set_temp("job",1);              
 return 1;       
 }

 else 
 tell_object(me,"���˶���˵��������ȥ������£�����͵������\n");
 return 1;
 }
int accept_object(object me, object ob)
{
        
        command("smile");
        if((string)ob->query("id")=="xian cai") 
        { 
                remove_call_out("destroying");
                call_out("destroying", 1, this_object(), ob);

                if(me->query_temp("job")!=1) 
                return notify_fail("���˶���Ц��˵�����ã����������������أ���\n"); 
                if(me->query_temp("cai")!=1)
                return notify_fail("���˶���Ц��˵�����ã����������������أ���\n");        

                  command("say ̫���ˣ����������Ÿ���������أ�");
                  me->delete_temp("job"); 
                  me->delete_temp("cai");
                  me->add("combat_exp",10);
                  me->add("potential",5); 
                  tell_object(me,HIY"��õ��˻𹤵��˵Ľ�����\n"NOR,me);

                return 1;
        }
}
void destroying(object me, object ob)
{
        destruct(ob);
        return;
}


