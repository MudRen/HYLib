 // garrison.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("����", ({ "xing rui","rui" }) );
        set("long",
 "һ����С�����ˣ�ӥ���ǡ���������������֮ɫ��˫����������߰�
͹�𣬿����ǵ��Ǹ���µ�������һ�����ӥצ��һ��Ĺ���\n"); 
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
    
        set("title", "���ϸ� �ܲ�ͷ");
        set("age",62); 
        set("str", 50);
        set("cor", 46);
        set("cps", 25);
        set("agi", 60); 
        set("max_qi", 3200);
        set("combat_exp", 5800000);
        set("max_force",10000);
        set("force_factor",100);
        set_skill("unarmed", 200);
        set_skill("claw", 100);
        set_skill("dodge", 300);
        set_skill("parry", 800);
  

        
        set("chat_chance", 1);
        set("chat_msg", ({
"���ܲ�ͷ��һ˫��������Ŀ����㣬�ƺ�Ҫ���㿴���Ƶġ�\n",
        }) ); 
        setup();
    carry_object("/clone/misc/cloth")->wear(); 
}  
void greeting(object ob)
{
   if( !ob || environment(ob) != environment() ) return;
        if(ob->query("class")!="official" && random(2)==0)
        {
                message_vision("������ͷ��$N˵�����������˹ٸ��صأ����������˷������������Ҵ������\n",ob);
                message_vision("���۽�$N�Ұ������\n",ob);
                ob->move("/d/jinan/street5");
        }
} 
void init()
{
        ::init();
        if( interactive(this_player()) ) {
                remove_call_out("greeting");
                call_out("greeting", 1, this_player());
        }        
}       
