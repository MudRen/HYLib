// this npc will duplicate anyone who he/she lost his fight to....
#include <ansi.h>
#define CHAMPION_FILE "/data/npc/champion1.o"
inherit NPC;
void loadall(object me);
string id1;
void find(string id);
int changeshape(object winner);
void create()
{
	string info,name,id,file;
        set_name( "����" , ({ "numberone" }) );
	setup();
	info = read_file(CHAMPION_FILE);
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
		restore_object(file);
        set_name( name , ({ id }) );
        delete("env");
        set("attitude", "aggressive");
        reset_action();
        delete_temp("already_loaded");
        loadall(this_object());
        set("title", HIC "��������" NOR);
	
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
	string name,id,nick;
	winner_file = winner->query_save_file();
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s�����ڿ�ʼ�������µ����������ˣ��� \n",
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
	set("title", HIC "��������" NOR);	
	set("nickname",nick);
		   
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
{	add_action("do_yao","yaozhang");
	if(!query_temp("already_loaded"))
		loadall(this_object());
	return;
}
int accept_fight(object me)
{
	return 1;
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
int do_yao()
{
	object zhang,me,ob;
	me = this_player();
	ob = this_object();
	zhang = new(__DIR__"zheng");
	if(ob->query("id")==me->query("id") && (!present("shenstaff",me)))
	{find(id1);
	zhang->move(me);
	message_vision("$N����$nһ�����ȡ�\n",ob,me);
	return 1;
	}
tell_object(me,"��ϹҪʲô��\n");
return 1;
}
void find(string id)
{
object *ulist,*ilist;
object ob;
int i,j;
ulist  =  users();
	i  =  sizeof(ulist);
while (i--) {
	//if(ulist[i]->query("id")== id ) {
	if  (present  ("shenstaff",ulist[i]))
	{
	ilist  =  all_inventory(ulist[i]);
	j=sizeof(ilist);
	while (j--) {
	ob = ilist[j];
	if(ob->query("id")=="shenstaff")
	destruct(ob);
	}
message_vision(HIY"$N���ϵ����Ȼ���һ����â������Զ����\n"NOR,ulist[i]);
	}
}
}
