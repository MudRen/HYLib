// this npc will duplicate anyone who he/she lost his fight to....
#include <ansi.h>
#define CHAMPION_FILE "/data/npc/champion_wd.o"
inherit NPC;
inherit F_MASTER;
void loadall(object me);
string id1;
void find(string id);
void changeshape(object winner);
void create()
{
	string info,name,id,file;
        set_name( "�����" , ({ "dizi" }) );
        set_temp("no_kill",1);
set("pubmaster",1);
	setup();
	info = read_file(CHAMPION_FILE);
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
		restore_object(file);
        set_name( name , ({ id }) );
        set("pubmaster",1);
        create_family("�䵱��", 40, "����");
	 delete("env");
        set("attitude", "aggressive");
        reset_action();
        delete_temp("already_loaded");
        loadall(this_object());
        this_object()->set_max_encumbrance(100000000);
        this_object()->clear_condition();
        set("title", HIY "�䵱�����Ŵ����" NOR);
	 set_temp("no_kill",1);
	carry_object("clone/weapon/gangjian")->wield();
	carry_object("clone/misc/cloth")->wear();

}
	
		
}
void lose_enemy(object winner)
{
	remove_call_out("changeshape");
	call_out("changeshape",2,winner);
	return;
}
void changeshape( object winner)
{
	string winner_file;
	object zheng;
	string name,id,nick;
        if (!userp(winner))
        return notify_fail("�㲻����ң��ǻ�����.\n");
	if( (string)winner->query("family/family_name") != "�䵱��" ) 
	return notify_fail("ֻ���䵱�ɵ��Ӳ�����������֮λ��\n");

	winner_file = winner->query_save_file();
        CHANNEL_D->do_channel(this_object(), "party",
        sprintf( "%s�����ڿ�ʼ���䵱���µ����Ŵ�����ˣ��� \n",
        winner->name(1)));
	write_file(CHAMPION_FILE,sprintf("%s %s %s",
	winner_file,winner->query("id"),winner->query("name")),1);
	restore_object(winner_file);
	name = winner->query("name");
	id = winner->query("id");
	set_name( name , ({ id }) );
	nick = winner->query("nickname");
	delete("env");
	set("attitude", "aggressive");
	reset_action();
	delete_temp("already_loaded");
	loadall(this_object());	
	set("title", HIY "�䵱�����Ŵ����" NOR);	
	set("nickname",nick);
	zheng = new(__DIR__"ling_wd");
	find(id);
	zheng->move(winner);
	message_vision("���Ŵ���Ӹ���$Nһ���䵱�ɵ����ơ�\n",winner);
	
	 set_temp("no_kill",1);

	   
return;
}

void loadall(object me)
{
        int MAX = 3;
        string name,id, *created;
        int i,j;
        object thing, *inv;
	inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        destruct(inv[i]);
                }

        id = me->query("id");
        created = get_dir(DATA_DIR + "login/" + id[0..0] + "/" + id + "/");
        for(j=0; (j<sizeof(created) && j < (MAX+1) ); j++)
        if( sscanf(created[j], "%s.c", name) == 1 )
                {
	thing = new( DATA_DIR + "login/" + id[0..0] + "/" + id +
 	"/" + name + ".c");
                        if(thing->move(me)) 
			{
			thing->wield();
			thing->wear();
			} 
                }
	me->reset_action();
        me->set_temp("already_loaded",1);
	return;
}
void init()
{
	if(!query_temp("already_loaded"))
		loadall(this_object());
        add_action("do_yao","want");
	return;
}

int do_yao()
{
	object ob,kele,hbb;
	ob = this_player();
if (this_player()->is_busy())
return 0;
	if( (string)this_player()->query("id") == query("id") || wizardp(this_player())) 
{
	command("give silver to "+(string)this_player()->query("id")+"");
	command("give coin to "+(string)this_player()->query("id")+"");
	command("give gold to "+(string)this_player()->query("id")+"");
	command("give Thousand-cash to "+(string)this_player()->query("id")+"");
	command("say �ã��������������գ�");
	this_player()->start_busy(6);
	return 1;
}
}
int accept_fight(object me)
{
object ob;
ob=this_object();
	if( (string)this_player()->query("family/family_name") != "�䵱��" ) 
	return notify_fail("ֻ���䵱�ɵ��Ӳ�����������֮λ��\n");
       if (this_player()->query("combat_exp") < 100000 || this_player()->query("age") <= 18)
        return notify_fail("������������Գ�Ϊ�����.\n");

       command("say �ã������ҾͿ��Գ�Ϊ���Ŵ���ӣ�");
 if (!ob->query_skill_mapped("unarmed"))
{
ob->set_skill("gedoushu",this_player()->query_skill("force"));
ob->map_skill("unarmed", "gedoushu");
ob->map_skill("parry", "gedoushu");
}
 if (!ob->query_skill_mapped("parry"))
{
ob->set_skill("gedoushu",this_player()->query_skill("force"));
ob->map_skill("unarmed", "gedoushu");
ob->map_skill("parry", "gedoushu");
}	return 1;
	  
}
void die()
{
        object ob;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);

        if( !ob ) return;

	changeshape(ob);
	return;
}
void find(string id)
{
object *ulist,*ilist;
object ob;
int i,j;
ulist  =  users();
	i  =  sizeof(ulist);
while (i--) {
	if  (present  ("wdling",ulist[i]))
	{
	ilist  =  all_inventory(ulist[i]);
	j=sizeof(ilist);
	while (j--) {
	ob = ilist[j];
	if(ob->query("id")=="wdling" && !userp(ob))
	{
	destruct(ob);
			}
	}
message_vision(HIY"$N���ϵ��䵱�����Ʋ�������ˡ�\n"NOR,ulist[i]);
	}
}
}
int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timem"))      
		who->set_temp("learn_timem", 0);

	if( !ob->query("money_id") )
		return 0;		

	if( (string)this_player()->query("family/family_name") != query("family/family_name")) 
	return notify_fail("ֻ�б��ɵ��Ӳ��ܵ�����ѧ����\n");

	if(who->query_skill("force",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("force",1)<60)
			i=ob->value() / 80;
		else
		{
			if(who->query_skill("force",1)<100)
				i=ob->value() / 150;
			else
				i=ob->value() / 300;
		}
	}
	who->add_temp("learn_timem",i);
command("say ������Ϊ���ɾ��ľ������Ҿ�ָ�������ֹ���ɣ�");
//      message_vision("��������$N˵������Ȼ�������ѧ�ҵ��书���Ҿͳ�ȫ��ȫ��ɡ�\n",who);

	return 1;
}

int recognize_apprentice(object ob)
{

	if( (string)ob->query("family/family_name") != this_object()->query("family/family_name")) 
	return notify_fail("ֻ�б��ɵ��Ӳ��ܵ�����ѧ����\n");

	if( ob->query_temp("learn_timem") <= 0) return 0;
else         
ob->add_temp("learn_timem",-1);
return 1;
}
