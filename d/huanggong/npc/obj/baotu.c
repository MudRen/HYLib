#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY "���������ͼ" NOR, ({ "daqing baotu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
set("no_get",1);
set("no_drop",1);            
set("value",0);            
            set("material", "paper");
            set("long", HIY"һ���������ʮ���¾����ı���ͼ������Բ鿴��chakan����\n"NOR);
          }

    setup();
}
void init()
{
	if(environment(this_object())==this_player())
	add_action("do_read","chakan");
	add_action("do_go","go");
}

int do_read(string arg)
{
object me;
mapping exits;
string *dirs;
string thisdir;
me=this_player();
if(arg != "daqing baotu" && arg != "���������ͼ") return 0;
if(!environment(me))
{
tell_object(me,"�������޷�����ͼ��\n");
 return 1;
}
if(!environment(me)->query("exits"))
{
tell_object(me,"��ͼ��ʾ����ͱ����޹أ�\n");
 return 1;
}
if(this_object()->query("lastck") ==environment(me)->query("short"))
{
tell_object(me,"��ͼ���Ǹոո��߹����������ȥ��?\n");
 return 1;
}

if(environment(me)->query("short")!="���ŷ�"
&& !this_object()->query("lmf"))
{
tell_object(me,"��ͼ�����㱦���ڹ������ŷ帽��������ȥ�����!\n");
 return 1;
}
if(environment(me)->query("short")=="���ŷ�"
&& environment(me)->query("already")
&& !this_object()->query("lmf"))
{
tell_object(me,"�������ˣ����������Ѿ��ѱ���������!\n");
return 1;
}


if(find_call_out("markit")== -1)
//call_out("markit",3,me);
call_out("markit",random(60)+20,me);
if( !mapp(exits = environment(me)->query("exits")) ) 
{
tell_object(me,"���������Ӧ�þ����⸽����\n");
return 1;
}
        dirs = keys(exits);
        thisdir = dirs[random(sizeof(dirs))];
	set("thisdir",thisdir);
	tell_object(me,HIY"ͼ����ʾ���������Ӧ����"+thisdir+"�ķ���\n"NOR);
if (environment(me)->query("short")=="���ŷ�")
{
this_object()->set("lmf",1);
environment(me)->set("already",1);
}
this_object()->set("lastck",environment(me)->query("short"));
	return 1;
}

int do_go(string arg)
{
	if(arg==query("thisdir"))
	this_player()->add_temp("going",1);
	return 0;
}
int markit(object me)
{
object gold;
int i;
//if(me->query_temp("going") <= 3 || environment()!=me) return 1;
if(me->query_temp("going") <= 20 || environment()!=me) return 1;
if(!query("already"))
{
tell_object(me,HIY"\n\n��˫��һ�����ӡ����������ͼ����ָʾ�ĵط��ڳ������Ļƽ𣬺����ɸ����䣡\n"NOR);
gold = new("/clone/money/gold");
i=random(1001)+500;
gold->set_amount(i);
gold->move(me);
me->delete("huanggong");
me->delete_temp("going");
set("already",1);
message("channel:chat", HIC"���������š�"GRN + me->query("name")+"����"+HIY"���������:�ƻƽ�" + chinese_number(i)+HIY"����\n"NOR,users() );
destruct(this_object());
}
return 1;
}

