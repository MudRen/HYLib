#include <ansi.h>
inherit NPC;
void create()
{
        set_name("ֵ�ڱ�", ({ "wulapo garrison", "garrison" }) );
        set("long",
"���Ǹ�����ִ���س������ֵ�ڱ�����Ȼ��������������������ֵ�ڱ��ǵ��书\n"
"ʵ��ƽ����������������֯���м��ɵ�սʿ��˭Ҳ�����׵��������ǡ�\n"
"�����Ҳ��Ҫ�������ǡ� \n");
        set("attitude", "heroism");
        set("str", 27+random(10));
        set("vendetta", "authority");
        set("cor", 26);
        set("cps", 25);
        set("combat_exp", 500000);  
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "ֵ�ڱ��ȵ�������������������־͸���\n",
                "ֵ�ڱ��ȵ����󵨵��񾹸Ҿܲ������ˣ����ˣ�\n"
        }) ); 
        set_skill("unarmed", 70+random(100));
        set_skill("dagger", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("blade", 270+random(100));

        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100); 
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
}
