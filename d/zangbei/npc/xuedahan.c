#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("Ѧ��",({"xue dahan","xue","dahan"}));
        set("title","���ֺú�");
        set("long","һ����߰˳ߵı��δ󺺣���򼸺���ƽ��������һ˫���Ȱ��
���ִ������������Ѹǹ���ϥ�ǣ�����ȧ�Ǹ��ʣ���������ɨ���
��Ũü��һ�Ŵ��졣�����ϴ����·���Ȼ�������ƣ���һվ��
�����������ݣ����˿��ź��¡�\n");
        set("gender","����");
        set("age",32);
                set("reward_npc", 1);
       set("difficulty", 20);
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        set("no_busy", 9);
                       set("class","knight");
        set_skill("unarmed", 180);
       

        set_skill("axe", 200);
        set_skill("literate", 140);
        set_skill("dodge", 140);
        set_skill("move", 140);
        set_skill("parry", 160);
        set_skill("force", 200);

               

          
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        
       // set("death_msg",CYN"\n$N�ں޵�˵�����ҵĽ��������ǡ������εá���̫������������\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (:perform_action,"axe.jiuqipoxiao":),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "Ѧ�󺺻��Ƴ�������������ʮ���µ�ͷ���µ�ͷ��Ѫ��������������Ӣ���ᣬɱ�����ĳ�ͷ������\n",
           }) );                   
        

       // auto_npc_setup();("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}     
