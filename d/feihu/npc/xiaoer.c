// xiaoer.c �Ƶ�С��
//by steel
#include "ansi.h"
inherit NPC;
inherit F_DEALER;
int ask_chuangwang();
void create()
{
        set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��λ��С����������,���ڸ߸����˵��к����ˡ�\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/feihu/obj/jitui",
                "/d/feihu/obj/jiudai",        
        }));
        set("chat_msg_chance",10);
        set("chat_msg",
        ({
        "��,ĸ�׵��Ĳ�ʲ��ʱ��Ż��ѽ,�������ˡ���λ��Ϻ����ҡ�\n",
        (:command("sigh"):),
        }) );
         set("inquiry",([
        "����" :(:ask_chuangwang:),
        "����" :(:ask_chuangwang:),
         ]) );  
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{       
        object ob; 
        ob=this_player();
        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
int ask_chuangwang()
{
    object ob;
    object boots;
    
    ob=this_player();
    
   if(!ob->query_temp("given"))
    {
    command("tell "+ob->query("id")+" ��...,������Щ��ʲô,�Ҳ�֪����");
    say(YEL"��С���Ĳ����εĿ�����\n"NOR); 
    return 1;
    }
    else
    {
     command("tell "+ob->query("id")+" "+"��λ"+RANK_D->query_respect(ob)+"\n"+
      "����˼�ĸ��������˫��ɽѥ����ȥ�ɣ�ȥ���������õ��š�\n");
     boots=new("/d/feihu/obj/snow_boots");
     boots->set_amount(1);
     boots->move(ob);
     command("say ��õ��˱�ɽѥ��\n");
     ob->set_temp("given",0);
     return 1;  
    } 
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return 0;
        this_player()->set_temp("given",0);
        switch( random(2) ) {
                case 0:
                        say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��վƣ�ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "��С�����˴��֣�˵��������,��λ" + RANK_D->query_respect(ob)
                                + "���������\n");
                        break;
        }
}

int accept_object(object ob, object obj)
{
       if(!ob||environment(ob)!=environment() ) return 0;
       
       if(!objectp(ob) ) return 0;
   
       if( !present(obj,ob) )
        { 
         say("�����𣿣�\n");
         return 1;
        }  
        if(obj->query("id")=="bearheart")
        ob->set_temp("given",1);
        return 1;
}
