inherit NPC;
#include <ansi.h>
void create()
{
	set_name("�Է�", ({ "qiao fu", "qiao" }));
	set("title",  "������󽫾�" );
	set("long", 
"�����Ǵ������ԭ�󽫾���һ�ƴ�ʦ���Ĵ����֮һ��
��������һ���ɲ���������һ����ͷ����������ɫ��
׳����̬������������������Ǵ󽫾��а������硣��
�����ֲ����Ѷ�����ɽ�ּ��Բ񣬱ص����Ǹ�߳���
�Ƶ�ͳ����˧��\n");
              set("nickname", HIY "���Ը���" NOR );   
        set("gender", "����");
        set("age", 45);

        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("per", 25);
        set("str", 30);
        set("int", 20);
        set("con", 25);
        set("dex", 25);     
        set("max_qi", 11000);
        set("max_jing", 1500);
        set("neili", 12000);
        set("max_neili", 12000);
        set("jiali", 50);
        set("combat_exp", 1500000);
        set("score", 100000);

        set_skill("kurong-changong", 150);
        set_skill("tiannan-step", 150);
        set_skill("jinyu-quan", 150);
        set_skill("unarmed", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("cuff", 180);
        set("inquiry", ([
                "һ�ƴ�ʦ"   : "ʦ�������˼������档\n",
                "������"     : "������ʦ�����������䡣\n",
                "������"     : "������ʦ�����������ӡ�\n",
        ]) );
       map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-step");
        map_skill("cuff",  "jinyu-quan");  
        map_skill("parry", "jinyu-quan");
        prepare_skill("cuff", "jinyu-quan");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 100);

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
        
