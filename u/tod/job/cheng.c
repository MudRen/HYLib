// chengyaojia.c ������

#include <ansi.h>
inherit NPC;
#include "/u/tod/mi.h"

string ask_cancel(object me);

void create()
{
        set_name("������", ({"cheng yaojia", "cheng", "yaojia"}));
        set("title",HIW "����ׯ������" NOR);
        set("gender", "Ů��");
        set("age", 19);
        set("long", 
        "������ʮ�˾������ҵĽ����ٸ������λ����������������\n"

        );

        set("attitude", "friendly");

        set("str", 20);
        set("int", 23);
        set("con", 20);
        set("dex", 25);
        set("per", 30);

        set("qi", 1300);
        set("max_qi", 1300);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 2300);
        set("max_neili", 2300);
        set("jingli", 1500);
        set("max_jingli", 1500);
        set("jiali", 100);

        set("combat_exp", 300000);      

        set("inquiry", ([
                 "miyu" : (: ask_cancel :),
                "����" : (: ask_cancel :),
        ]) );

string ask_cancel(object me)
{
        me = this_player();
                 mi(me);

                return "��£���ѽ��";
 }

