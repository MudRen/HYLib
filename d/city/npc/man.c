#include <ansi.h>
inherit NPC;
int ask_me();
//int ask_gift();
int ask_bing();
void create()
{
       set_name("������ʿ", ({ "noname", "man" }));
        set("title",HIW"һ����ʦ"NOR);
	set("long", 
              "������������ʿ��û����֪������������\n"
              "��������ռ����飬�����������(book)��(shi).\n"
              );
        set("age", 57);
        set("class", "beggar");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 700);
	set("int", 40);
	set("con", 40);
	set("dex", 700);
	set("no_kill",1);
	set("qi",   99999999);
	set("jing", 99999999);
	set("eff_qi",   99999999);
	set("eff_jing", 99999999);
	set("max_qi",   99999999);
	set("max_jing", 99999999);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 0);
	set("combat_exp", 25000000);
	set("score", 50000);                
        set_skill("strike",200);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("force", 200);
	set_skill("parry", 210);
	set_skill("literate", 200);
	set_skill("canzhi-duanhun",300);
        map_skill("unarmed", "canzhi-duanhun");
        map_skill("parry", "canzhi-duanhun");


set("inquiry", ([
            "book": "���鹲����ʮ�������������help tasks����йط���֪ʶ��",
            "shi": "ֻ�п�"HIR"��"+HIC+"��"+HIY+"��"+HIM+"��"+HIG+"ʯ"NOR+CYN"�����ҵ����飬��ʯ��ʮ��һ�飡",
	     "mengzhu": (: ask_me :),
//	     "�±�":(: ask_bing :),
	    // "gift":(: ask_gift :),
            ]) );
       	setup();
}
int accept_object(object me, object ob)
{
object shi; 
if( ob->query("money_id") && ob->value() >= 2000)
{	
	 if (!present("xdshi", me))
	{
	shi = new("/clone/misc/findbook");
	command("say �ð�,"+me->query("name")+"��Ȼ����Ǯ���Ҿ͸���һ�飡\n");
	shi->move(me);
	message_vision("$N��һ��"HIR"��"+HIC+"��"+HIY+"��"+HIM+"��"+HIG+"ʯ"NOR"������$n��\n" , this_object(), me );
	} else 
	command("say �㲻������һ�������Ҫ��Ǯ��û�գ�\n");
return 1;
}

command("say лл�����Ҳ�Ҫ�ⶫ����");
return 0;
}
int ask_me()
{
if(this_player()->query("combat_exp")<1500000)  tell_object(this_player(),"������ʿ˵�����㾭��̫�ͣ���Ҫ���������������ɣ�\n");
else {
tell_object(this_player(),"������ʿ˵���� �ðɣ�����Σ�����أ�ǧ�������������������Σ�ա��Լ�С�İɣ�\n");
this_player()->move("/d/biwu/hole");
}
return 1;
}
int ask_bing()
{
object me,bing;
me = this_player();
if(!me->query("marks/nabing"))
{
message_vision("������ʿ�����ðɣ��͵�����$N�����������ɡ�������ʿ����$Nһֻ������±���\n",me);
bing = new("/clone/misc/yuebing");
bing->move(me);
me->set("marks/nabing",1);
}
else tell_object(me,"���Ѿ��ù�һ���±��ˣ������ã�\n");
return 1;
}
/*int ask_gift()
{
object me,gift;
me = this_player();
if(!me->query("marks/nagift"))
{
message_vision("������ʿ�����ðɣ��͵�����$N�Ĺ��������ɡ�������ʿ����$Nһֻ����ں����\n",me);
gift = new("/clone/misc/guogift");
gift->move(me);
me->set("marks/nagift",1);
}
else tell_object(me,"���Ѿ��ù�һ�κ���ˣ������ã�\n");
return 1;
}*/
