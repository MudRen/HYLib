//Npc �ȹ���ʮ��
//diabio(����)2003.3.1
#include <ansi.h>
inherit NPC;
int ask_tianxiang();
inherit F_MASTER;
void create()
{
        set_name("�ȹ���ʮ��", ({ "biguqing shilang", "shilang" }));
        set("long", "������糴彣�ĵ�ʦ���� \n");
        set("title", HIR"����������"HIY"����������"NOR);
        set("gender", "����");
        set("age", 40);
        set("attitude","peaceful");
        set("str", 90);
        set("dex", 190);
        set("con", 90);
        set("int", 90);
        set("per", 20);
        set("per",23);
        set("tianyu_1",1);
        set("max_qi", 600000);
        set("max_jing", 100000);
        set("max_neili", 500000);
        set("max_jing",1000);
              set("neili",500000);
        set("qi",600000);
        set("jing",10000);
        set("jing",10000);
        set("combat_exp", 19000000);
        set_skill("cuff",600);
        set_skill("dodge",600);
        set_skill("unarmed",600);
        set_skill("parry",600);
        set_skill("blade",600);
         set_skill("feitian-yujianliu",600);
         set_skill("shayi-xinfa",800);
        set_skill("force",600);
        set_skill("aikido",600);
        set_skill("wuxing-dun",600);
        set_skill("huoxinliu-jianfa",600);
        set_skill("xuanhualiu-quanfa",600);
        set_skill("literate",350);
        map_skill("cuff", "xuanhualiu-quanfa");
        map_skill("unarmed", "aikido");
        map_skill("dodge", "wuxing-dun");
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
        map_skill("parry", "feitian-yujianliu");
              set("inquiry", ([
           "����������":     "��ս��ʱ����ʼ����������������书��",
           "糴彣��":   "�������ǲ�Тͽ����"]) );
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "blade.jiu" :),
               (: perform_action, "blade.tianxiang" :),
               (: perform_action, "blade.longlianda" :),
               (: perform_action, "blade.suodi" :),
               (: perform_action, "cuff.sanchong" :),
               (: perform_action, "unarmed.niu" :),
               (: perform_action, "unarmed.qin" :),                                                            
               (: perform_action, "unarmed.yaozhan" :),                                                            
               (: perform_action, "dodge.break" :),                                                            
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/quest/weiguo/japan/obj/japanblade")->wield();
}
void unconcious()
{
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
        say( "�ȹ���ʮ��Ц��˵����ֻ����������书��\n");
        command("hehe");

}

void die()
{
        unconcious();
}