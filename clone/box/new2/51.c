#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"������"NOR, ({ "jihuiwan" }) );
    set_weight(1);
            set("no_put", 1);
            set("value", 88);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
            set("no_put", 1);
            set("no_steal", 1);
            set("no_beg", 1);
            set("no_pawn", 1);
            set("value", 88);
            set("treasure",1);
            set("unit", "��");
            set("material", "paper");
            set("long", "����֮һ�����þ��Ǻ��ҩ����\n");
          }

    setup();
}
void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
if (random(8)==1)
{
me->delete("szj/failed");
message_vision(HIG"$N�ٴλ���ƽ����վ��Ļ��ᣡ\n"NOR, this_player());
}
else if (random(8)==2)
{
me->delete("jiuyin/shang-failed");
message_vision(HIG"$N�ٴλ�ý�����ϲ�Ļ��ᣡ\n"NOR, this_player());
}
else if (random(8)==3)
{
me->delete("jiuyin/xia-failed");
message_vision(HIG"$N�ٴλ�ý�����²�Ļ��ᣡ\n"NOR, this_player());
}
else if (random(8)==4)
{
me->delete("zhou/jieyi");
me->delete("zhou/fail");
me->delete("zhou/failed");
message_vision(HIG"$N�ٴλ�ý�˫�ֻ����Ļ��ᣡ\n"NOR, this_player());
}
else if (random(8)==5)
{
me->delete("jiuyin/gumu-failed");
message_vision(HIG"$N�ٴλ�ý������Ĺ�Ļ��ᣡ\n"NOR, this_player());
        message_vision(HIG "$N�԰��������ȥ��ֻ����ȫ������˲���!\n" NOR, me);
}	
else 
{
me->set("betrayer",0);
message_vision(HIG"$N����ʦ�������㣡\n"NOR, this_player());
}
	destruct(this_object());
	return 1;
}