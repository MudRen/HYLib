//dadi.c ����ʹ
// [lsg 1999/11/24]

inherit NPC;
#include <ansi.h>;
int time_period(int timep,object me);
#include "../teamjob.c"
        void create()
{
        set_name("����ʹ", ({ "renwu shi", "shi", "renwu"}));
        set("title", HIC"��ɽ��"NOR);
        set("gender", "����" );
        set("age", 102);
        set("str", 50);
        set("int", 25);
        set("con", 30);
        set("dex", 30);
        set("per", 30);
        set("long", 
"һλ������ʹ��ר�Ÿ�������ɵ��Ӹ�������.\n");
        set("combat_exp", 50000000);
        set("shen_type", 1);

        set("attitude", "peaceful");
        set("max_qi", 35000);
        set("max_jing", 10000);
        set("neili", 55000);
        set("max_neili", 55000);
        set("jiali", 200);
        
        set_skill("force", 300);
        set_skill("zhemei-shou", 300);
        set_skill("unarmed", 500);
        set_skill("xiantian-qigong", 500);
        set("mp","��ɽ��");
         map_skill("unarmed","zhemei-shou");
       map_skill("force","xiantian-qigong");
        
        set("inquiry", ([
              "job"  : "���ɵ��ӿ�����������quest�����������Ҳ���Ϊ�����ǵġ�\n",       
 	      "��������"  : (: ask_jianxi :),
 	      "teamjob"  : (: ask_jianxi :),
 	      "����"  : (: ask_gift :),
 	      "gongxian"  : (: ask_gift :),
]) );

        setup();
        carry_object("/clone/cloth/cloth")->wear();

}
