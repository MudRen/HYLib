 inherit NPC;
#include <ansi.h>

void create()
{
        set_name("л����", ({ "xie changqing" }) );
        set("gender", "����");
        set("age", 25);
        set("long",
"һ�������Ӣ�������꣬�������ڲ����ţ�Ӣ���������ϣ�Ҳ����
һ������֮ɫ����\n"
);
      
        set("chat_chance", 1);
        set("chat_msg", ({
"л�����૵������һ����ᣬ�Ҳ��ܾ�����������Ϣ����ȥ��������ʱ
�����������ˣ���ʹ����������֮�£�����˭�ᴫ����ȥ����������
���˶���Ϊ�Լ�����ɡ���\n",
        }) ); 
        set("fly_target",1); 
        set("attitude", "friendly");
        set("title",HIG"���"NOR);
        set("nickname", HIG"��Ӣ��"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",2);
        set("class","legend");
        
        set("combat_exp", 3500000);        
        set("int", 30);
        set("cps", 20);
        set("spi", 30);
        set("fle",60);
        set("per",40);
        set("str",40);
        
        set("neili", 1000);
        set("max_neili",1000);
        set("force_factor", 90);
        set("atman", 1000);
        set("max_atman", 1000);
        set("mana", 500);
        set("max_mana", 500);
        
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        

          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("qidaoforce", 150);
        set_skill("fall-steps",150);
        set_skill("meihua-shou",150);

        
        map_skill("unarmed","meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge","fall-steps");


        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(5));
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
 

