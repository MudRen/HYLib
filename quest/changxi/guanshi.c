//������100�����II���������䣩
// guanshi.c ����ϷԺ����
//����lywin 2000/6/21 

#include <ansi.h>
#include <command.h>
inherit NPC;
void consider();
int do_gongzuo();
int ask_done();

mapping *changxi = ({ 
         ([ "changxi":"����","where":"city"   ]),
         ([ "changxi":"����","where":"beijing"  ]),
         ([ "changxi":"�ɶ�","where":"chengdu"]),   
         ([ "changxi":"����","where":"dali"   ]),   
         ([ "changxi":"��ɽ","where":"foshan" ]),   
         ([ "changxi":"Ȫ��","where":"quanzhou"]),   
         ([ "changxi":"����","where":"hangzhou"]),   
         ([ "changxi":"����","where":"lingzhou"]),   
         ([ "changxi":"����","where":"suzhou"]),   
                   });
mapping query_changxi()
{
        return changxi[random(sizeof(changxi))];
}

void create()
{
        set_name("����", ({"guan shi", "guan"}));
        set("gender", "����");
        set("age", 25);
        set("long", 
                "��������ϷԺ�Ĺ��¡�\n");
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
                "���" : (: ask_done    :),
                "����" : (: ask_done    :),
        ]) );

        setup();
        carry_object("clone/cloth/cloth")->wear();
}
int do_gongzuo()
{      
        mapping changxi,changxiwhere;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/changxi")>0)
    {
                tell_object(me,"��ȥ���ݰɡ�\n");
                return 1;
    } 
    else 
    if( me->query("combat_exp")>500000)
    {
                tell_object(me,"���Ѿ��������ˣ����ֹ��������������ˡ�\n");
                return 1;
    }
    changxi = this_object()->query_changxi();
    changxiwhere = changxi["where"];
    message_vision(CYN"���¶�$N˵������ȥ" + changxi["changxi"] + "�Ĵ���ϱ���һ�°ɡ�\n"NOR,me); 
        me->set_temp("obj/changxi", 1);
        me->set_temp("obj/where",changxiwhere);
        ob=new(__DIR__ "daoju");
        ob->move(me);
        return 1;   
}

int ask_done()
{      

        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/changxi")< 1)
    {
                tell_object(me,"�����������Ҫ�����񣿡�\n");
                return 1;
    } 
    if( me->query_temp("obj/done")< 1)
    {
                tell_object(me,"��û���������Ϊ�Լ�����ˣ���ȥ���ݰɡ�\n");
                return 1;
    }
    message_vision(CYN"���¶�$N˵�������ò�������Щ�����ɡ�\n"NOR,me); 
    me->add("combat_exp",80+random(30));
    me->add("potential",50+random(20));
    me->delete_temp("obj");
    ob=new("/clone/money/silver");
    ob->set_amount(5+random(20));
    ob->move(me);
    if (ob = present("changxi daoju", this_player()))
    {
       message_vision("���°ѳ�Ϸ�������˻�ȥ��\n",me);
       destruct(ob);
       return 1;
    }
    return 1;
}