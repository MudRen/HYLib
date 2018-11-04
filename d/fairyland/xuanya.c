// Room: /u/qingyun/jyzj/xuanya.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>

inherit ROOM;

int do_jump(string arg);

void create()
{
	set("short", HIY"����"NOR);
	set("long", @LONG
����������֮�ϣ�ͻȻ�ڶ��洫���������ƣ����������ɲ���ֻ�����漸
ֻ���������ͷ��������������צ���ƽУ�����Ҫʳ�Թ�����ֻ��֮����һ��
����׵�����Ͽ�ȣ��޷�������
LONG	);
	set("exits", ([
		"eastdown" : __DIR__"conglin2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
}

void init()
{
	add_action("do_jump", ({"jump", "tiao", "yue"}));
}

int do_jump(string arg)
{
        object me = this_player();

        if (arg == "down") { 
                message("vision", me->name() + "һ���������������¡�\n", environment(me), ({me}));
if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 50) {
message_vision("$Nһ�������������£����......\n", me);
me->unconcious();
return 1;
}
if (me->query_kar() >= 25) {
			if (me->query_skill("dodge", 1) >= 50) {
				write(HIR"\n������һ����ֱ��������Ԩ��ȥ������\n\n"NOR);
				write(HIR"\n��������ٶ�̫�죬�忪����֮��ֱ���¶飡����\n\n"NOR);
				write(HIR"\n��ֻ�����Է������������Ӳ��ϵ�����ˤ��......\n"
					   "ż�������ͱ�������֦���������ȥץ��������֮\n"
					   "��̫����֦������һ�����ˣ�����\n\n"NOR);
				write(HIY"\n������������ٶ�����һ�㣬��æʹһ�С����������������εı�ס��һ��������\n\n"NOR);
        		        me->move(__DIR__"songshu");
                		message("vision", me->name() + "�����ı�ס�����С������\n", environment(me), ({me}));
			}
			else {
				write(HIR"\n������һ����ֱ��������Ԩ��ȥ������\n\n"NOR);
				write(HIR"\n��������ٶ�̫�죬�忪����֮��ֱ���¶飡����\n\n"NOR);
				write(HIR"\n��ֻ�����Է������������Ӳ��ϵ�����ˤ��......\n"
					   "ż�������ͱ�������֦���������ȥץ��������֮\n"
					   "��̫����֦������һ�����ˣ�����\n"NOR);
				write(HIR"\n"
					"		.\n"
					"		.\n"
					"		.\n"NOR);
	                	me->move(__DIR__"xuedi");
			        me->unconcious();
        	        	message("vision", me->name() + "��������ˤ��������\n", environment(me), ({me}));
			}
		}
	 	else {
			if (me->query_skill("dodge", 1) >= 150) {
				write(HIR"\n������һ����ֱ��������Ԩ��ȥ������\n\n"NOR);
				write(HIR"\n��������ٶ�̫�죬�忪����֮��ֱ���¶飡����\n\n"NOR);
				write(HIR"\n��ֻ�����Է������������Ӳ��ϵ�����ˤ��......\n"
					   "ż�������ͱ�������֦���������ȥץ��������֮\n"
					   "��̫����֦������һ�����ˣ�����\n\n"NOR);
				write(HIY"\n������������ٶ�����һ�㣬��æʹһ�С����������������εı�ס��һ��������\n\n"NOR);
        		        me->move(__DIR__"songshu");
                		message("vision", me->name() + "�����ı�ס�����С������\n", environment(me), ({me}));
			}
			else if (me->query_skill("dodge", 1) >= 20) {
				write(HIR"\n������һ����ֱ��������Ԩ��ȥ������\n\n"NOR);
				write(HIR"\n��������ٶ�̫�죬�忪����֮��ֱ���¶飡����\n\n"NOR);
				write(HIR"\n��ֻ�����Է������������Ӳ��ϵ�����ˤ��......\n"
					   "ż�������ͱ�������֦���������ȥץ��������֮\n"
					   "��̫����֦������һ�����ˣ�����\n"NOR);
				write(HIR"\n"
					"		.\n"
					"		.\n"
					"		.\n"NOR);
				me->move(__DIR__"xuedi");
				me->unconcious();
				message("vision", me->name() + "��������ˤ��������\n", environment(me), ({me}));
			}
			else {
				write(HIR"\n������һ����ֱ��������Ԩ��ȥ������\n\n"NOR);
				write(HIR"\n��������ٶ�̫�죬�忪����֮��ֱ���¶飡����\n\n"NOR);
				write(HIR"\n��ֻ�����Է������������Ӳ��ϵ�����ˤ��......\n"
					   "ż�������ͱ�������֦���������ȥץ��������֮\n"
					   "��̫����֦������һ�����ˣ�����\n"NOR);
				write(HIR"\n"
					"		.\n"
					"		.\n"
					"		.\n"NOR);
		                me->move(__DIR__"xuedi");
//			        me->set_temp("last_damage_from", "��������" + "ˤ");
				me->die();
	        	        message("vision", me->name() + "��������ˤ��������\n", environment(me), ({me}));
			}
		}
		return 1;
	}
	return 0;
}				
     
