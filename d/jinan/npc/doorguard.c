#include <ansi.h> 
inherit NPC;
int give_guard();
void create()
{
        set_name("����", ({ "yinxian" }) );
        set("long",
                "һ�����»����Ĵ���������Ҳ���ղ������������Զ��ֶ����
��������为����ϸ�����������,��͢������������ٻ���(guard).\n"); 
        set("attitude", "heroism");
        set("title", "��͢���� ��Ʒ��������");
        set("vendetta_mark","authority");
        set("reward_npc", 1);
        set("difficulty", 10); 
        set("cor", 26);
        set("cps", 55); 
        set("combat_exp", 5000000); 
        set_skill("unarmed", 150+random(500));
        set_skill("blade", 100+random(500));
        set_skill("parry", 100+random(500));
        set_skill("dodge", 100+random(500));
        set_skill("move", 100+random(500));
        set_skill("qiusheng-blade",150);
        set_skill("liuquan-steps",150); 
        map_skill("parry","qiusheng-blade");
        map_skill("blade","qiusheng-blade");
        map_skill("dodge","liuquan-steps");
        map_skill("move","liuquan-steps"); 
        set_temp("apply/damage", 200+random(200));
        set_temp("apply/armor", 200); 
        set("chat_chance", 1);
        set("chat_msg", ({
"�����۾������Ź⣬��Ц�����������Ҷ�³������Ŵ�ѩ��ս�Ͻ���֮\n�ա������������ȴ�����з�������ʵ�����뿪���á�����\n"
        }) ); 

    setup(); 
        carry_object(__DIR__"obj/yafu")->wear();
    carry_object(__DIR__"obj/peidao")->wield();
} 
