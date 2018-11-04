// Npc: /kungfu/class/nanshaolin/fangxiang.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;
string ask_me();
string ask_fangzhang();
int do_massage(string arg);

void create()
{
	set_name("����", ({ "fang xiang", "fang", "xiang"}));
	set("long", "����һλ���Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
		"���ýݣ������ƺ�ѧ��һ���书��\n");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50);
	set_skill("zhanzhuang-gong", 60);
	set_skill("shaolin-cuff", 60);
	set_skill("shaolin-leg", 60);
	set_skill("yiwei-dujiang", 60);
	set_skill("boluomi-hand", 60);
	set_skill("jingang-strike", 60);
	set_skill("wuxiang-finger", 60);
	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("yijinjing", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("luohan-quan", 50);
	set_skill("strike", 50);
	set_skill("sanhua-zhang", 50);
	set_skill("sanhua-zhang", 50);
	set_skill("finger", 50);
	set_skill("yizhi-chan", 50);
	set_skill("sword", 50);
	set_skill("damo-jian", 50);

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("strike", "sanhua-zhang");
	map_skill("finger", "yizhi-chan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
	prepare_skill("strike", "sanhua-zhang");
	prepare_skill("finger", "yizhi-chan");

	set("inquiry", ([
		"����"       : (: ask_me :),
		"��ʮ������" : (: ask_me :),
		"���̷���"   : (: ask_fangzhang :),
	]));
	create_family("��������", 21, "����");
	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(__DIR__"changjian")->wield();
}

void init()
{
	add_action("do_massage","massage");
}

string ask_me()
{
	mapping fam, skl; 
	object ob;
	string *sname;
	int i;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "��������")
		return RANK_D->query_respect(this_player()) +"�뱾��������������֪�˻��Ӻ�̸��";
	if ( (int)this_player()->query("guilty") > 0 )
		return RANK_D->query_respect(this_player()) +"���۷����䣬������������ܸ��������ͣ�";
	if ( (int)this_player()->query_int() < 30 )
		return RANK_D->query_respect(this_player()) +"���ʲ��������ܽ���ؾ�¥��";
	skl = this_player()->query_skills();
	sname = sort_array( keys(skl), (: strcmp :) );
	for(i=0; i<sizeof(skl); i++)
	{
		if (skl[sname[i]] < 50) 
		return RANK_D->query_respect(this_player()) +"���������������ʸ���ȡ���͡�";
	}
	if ( (int)this_player()->query_skill("buddhism",1) < 80 )
		return RANK_D->query_respect(this_player()) +"��ѧϰ�ϳ��书����Ҫ�Ը���𷨻������ǵ�������";
	ob = new("/d/nanshaolin/obj/allow-letter");
	ob->move(this_player());
	message_vision("$N���һ�����͡�\n",this_player());
	return "�ðɣ�ƾ������ͣ�������ɽ���ؾ����¥��ϰ�ϳ��书��";
}

string ask_fangzhang()
{
	mapping fam, skl; 
	object ob=this_player(), me=this_object();

	if(ob->query("massage_name"))
		return ("�Ѿ������ڷ��̷����ˡ�\n");
//	if(ob->query("combat_exp") >= 10000 && !wizardp(ob))
//		return ("���Ѿ����˻����ˣ�û��Ҫ������������ˡ�\n");
	if((string)ob->query("family/family_name") != "��������")
		return ("�������ֵ��Ӳ����칤����");
	if((string)ob->query("class") != "bonze" && !wizardp(ob))
		return ("�׼ҵ��Ӳ����칤����");
	if(ob->query_temp("job_name"))
		return ("�㲻���Ѿ����˹����𣿻�����ȥ����\n");
	me->set("massage_name",ob->query("name"));
	ob->set_temp("job_name","���̷���");
	ob->set_temp("massage", 1);
	return "��������Ƿ��̷��ɡ����ȥ�ɡ�";
}

int do_massage(string arg)
{
int i1,i2;
	object ob=this_player(), me=this_object();

	if(!arg || arg != "ok") return 0;
	if(!ob->query_temp("massage")) return 0;
	if(!ob->query_temp("mark/��Ħ��")) return 0;
	if(ob->query("name")==me->query("massage_name")) 
	{
		command("pat "+ob->query("id"));
		command("say ����Ϊ���ˣ�����ȥ��Ϣ�ˣ������ӷ�");
		i1=(int)(ob->query_skill("buddhism",1)/12);
		i2=(int)(ob->query_skill("buddhism",1)/10);
		if (i1>80) i1=80;
		if (i2>120) i2=120;	
		ob->add("potential",i1+20);
		ob->add("combat_exp",i2+50);
		me->delete("massage_name");
		ob->delete_temp("job_name");
		ob->delete_temp("massage");
		ob->delete_temp("massageed");
		ob->delete_temp("mark/��Ħ��");
		return 1;
	}
	return notify_fail("�����ʵ�����ղŽ�ȥ���̷����ˣ�\n");
}
#include "fang.h";

