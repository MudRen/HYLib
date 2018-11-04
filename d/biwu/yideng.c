// yideng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("һ�ƴ�ʦ", ({"yideng-dashi", "dashi", "yideng"}));
    set("nickname", HIG "�ϵ�" NOR );
    set("gender", "����");
    set("age", 52);
    set("long", 
        "�����Ǻųơ��ϵۡ���һ�ƴ�ʦ�����������ˣ�����ѷλΪɮ��\n"
        "��ʦһ�����ƣ��������\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("qi", 13000);
    set("max_qi", 13000);
    set("jing", 13000);
    set("max_jing", 13000);
    set("neili", 13500);
    set("max_neili", 13500);
    set("jiali", 100);
	
    set("combat_exp", 13000000);
    set("score", 0);
    set_skill("force", 350);             // �����ڹ�
    set_skill("finger", 370);            // ����ָ��
    set_skill("dodge", 350);             // ��������
    set_skill("parry", 350);             // �����м�
    set_skill("liumai-shenjian", 380);   // ������
    set_skill("taixuan-gong", 380);      // ̫����
    set_skill("lingxu-bu", 380);         // ���鲽
    set_skill("literate",380);           // ����ʶ��
	
    map_skill("force"  , "taixuan-gong");
    map_skill("finger" , "liumai-shenjian");
    map_skill("dodge"  , "lingxu-bu");
    map_skill("parry"  , "liumai-shenjian");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);
	set("chat_chance_combat", 80);
 	 set("chat_msg_combat", ({
                (: perform_action, "finger.liumaijinhun" :),
        }) );



    prepare_skill("finger", "liumai-shenjian");

    create_family("����μ�", 17, "����");
    setup();

    carry_object("/clone/misc/cloth")->wear();
}
