// huang.c
inherit NPC;
inherit F_MASTER;
#include "huangjobhy.c"
void create()
{
    set_name("����", ({"huang rong", "huang", "rong"}));
    set("gender", "Ů��");
    set("age", 36);
    set("long", "���Ǳ��������ķ��ˣ���а��ҩʦ�İ�Ů��ǰ��ؤ�������\n");

    set("attitude", "peaceful");
    set_max_encumbrance(100000000);   
    set("per", 30);
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 2000);
    set("max_qi", 2000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 2000);
    set("max_neili", 2000);
    set("jiali", 0);
       
    set("combat_exp", 5000000);
    set("score", 0);
       
    set_skill("force", 320);
    set_skill("bibo-shengong", 320);
    set_skill("unarmed", 320);
    set_skill("luoying-zhang", 320);
    set_skill("dodge", 180);
    set_skill("anying-fuxiang", 320);
    set_skill("parry", 120);
    set_skill("sword", 120);
    set_skill("luoying-shenjian", 320);
    set_skill("qimen-wuxing", 320);
    set("inquiry", ([
		 "job"   : (: ask_job :),
         "����"  : (: ask_gonglao :),
         "fangqi": (: ask_fangqi :),
         "����"  : (: ask_fangqi :),
		 ]));      
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
       
    create_family("�һ���", 2, "����");
    setup();
    carry_object("/kungfu/class/taohua/obj/ruanwei")->wear();
    carry_object("/kungfu/class/taohua/obj/shudai")->wear();

}

