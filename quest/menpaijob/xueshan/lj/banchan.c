//Cracked by Kafei
// /d/hangzhou/npc/kumu.c
// by aln  2 / 98
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_job();

void create()
{
	set_name(HIY"�������"NOR, ({
		"banchan huofo",
		"banchan",
		"huofo",
	}));
	set("long",
"���������ѩɽ���е��ĸ�ɮ���Է��о�����о��� \n"+
"����һ����ɫ���ģ�ͷ��ɮñ����ü��Ŀ������Ըߣ�\n"+
"̫��Ѩ΢͹��˫Ŀ��������\n"
	);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("qi", 26500);
set_temp("no_kill",1);
	set("max_qi", 26500);
	set("jing", 8000);
	set("max_jing", 8000);
	set("neili", 26000);
	set("max_neili", 26000);
	set("jiali", 50);
	set("combat_exp", 800000);
	set("score", 100);

	set_skill("lamaism", 270);
	set_skill("force", 270);
	set_skill("hunyuan-yiqi", 270);
	set_skill("dodge", 270);
	set_skill("shaolin-shenfa", 270);
	set_skill("finger", 270);
	set_skill("nianhua-zhi", 270);
	set_skill("parry", 270);
	set_skill("buddhism", 270);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "nianhua-zhi");
	map_skill("finger", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");

        set("inquiry", ([
                "����" : (: ask_job :),
                "job" : (: ask_job :),
        ]));

	setup();

        carry_object("/d/xueshan/obj/y-jiasha")->wear(); 
        carry_object("/d/xueshan/obj/sengmao")->wear(); 
 }

string ask_job()
{
        object obj, place, *inv, me = this_player();

        if( is_fighting() || is_busy() )
                return "����æ�š�";
        if( me->query("family/family_name") != "ѩɽ��")
                return "���£�ֻ�뱾�¸�ɮÿ�콲��˵����";
        if( (string)me->query("class") != "bonze" )
                return "�����ӷ����գ����գ�ʩ�����Ƿ��ŵ��ӣ�������ذɡ�";

        if( (int)me->query_skill("lamaism", 1) < 50 )
                return "����ֻ���������ķ������ǰ������˵��";


        if( me->query_condition("xsjob") )
                return RANK_D->query_respect(me) + "�Ѿ��ڽ���˵���ˡ�";
        if( me->query_temp("xsjob2") )
                return RANK_D->query_respect(me) + "�Ѿ��ڽ���˵���ˡ�";

        if( me->query_condition("xsjob2") )
                return RANK_D->query_respect(me) + "�ոս������ˣ���Ϣһ�������ɡ�";

        command("nod");
me->set_temp("xsjob2",1);
        me->apply_condition("xsjob", 3 + random(3));


        return "̫���ˣ���������һ�����¸�ɮǰ������˵��";
}

