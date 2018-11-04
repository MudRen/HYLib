//Cracked by Kafei
// sjsz/square.c �Խ�ɽׯ
// Apache for Group BWDH 09/98

#include <ansi.h>
inherit ROOM;
#include "kantai.h"
#define BOARD "/clone/board/bwboard"

string long_desc();

void create() {
	 set("short", HIC"�Խ�ɽׯ"NOR);
	 set("long", (: long_desc :));
	 set("exits", ([
		  "south" : __DIR__"kantai_s",
		  "north" : __DIR__"kantai_n",
		  "east"  : __DIR__"gamble_room",
		  "up"    : __DIR__"wizroom",
		  "out"   : __DIR__"gate",
	 ]));
	 set("no_fight", 1);
	 set("no_steal", 1);
	 set("no_practice", 1);
	 set("valid_startroom", 1);
    set("objects", ([
		  __DIR__"obj/control"     : 1,
	 ]));

	 setup();
}

init()
{
	init_kantai();
}

string long_desc() {
	 string desc, desc_temp;
	 object board,  player;
	 mapping entry;
	 int scoreA, scoreB, winA, winB, tieA, tieB, loseA, loseB;
	 int i, exchange, j;
	 string id, sTeam;

	 desc = "��������������µ��Խ�ɽׯ��\n";

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
		  board = load_object(BOARD);
		  if (!objectp(board))
				//return notify_fail("�Ҳ����������ɼ��档\n");
				return desc;
	 }


	 desc = desc + HIG"
�������������������������������������ִ����������������������������������������
��������������������������������������������������������������������������������
�ӱ�  ����     ����  ʤ  ƽ  �� ��Ա                                      \n";

	 desc_temp = "";

	 for(i = 0; i < sizeof(board->query("team")); i++) {
		  sTeam = "team/" + sprintf("%d", i + 1);
		  entry = board->query(sTeam);
		  if( !entry ) break;
		  desc_temp += sprintf("%4d  %12s  %4d  %2d  %2d  %2d ",
					 i+1,
					 (string)entry["title"],
					 (int)entry["score"],
					 (int)entry["win"],
					 (int)entry["tie"],
					 (int)entry["lose"]
					 );
		  for( j = 0; j< sizeof( board->query(sTeam + "/names" ) );j++)
		  {
				id = board->query( sTeam+"/ids/"+sprintf("%d",j+1) );
				if(!id)continue;
				player = find_player(id);
				if( (j-1)%3==2 )
				{
					desc_temp += "\n                               ";
				}

				if( objectp(player) && userp(player) )
				{
					desc_temp += sprintf("%8s(%5d)",board->query(sTeam + "/names/"+sprintf("%d",j+1)),player->query("sjsz/bw_score") );
				}
				else
					desc_temp += sprintf("%8s(�� ��)",board->query(sTeam + "/names/"+sprintf("%d",j+1)));
		  }
		  desc_temp += "\n";
	 }
	 desc = desc + desc_temp + "
________________________________________________________________________________\n"NOR;

	//write(desc);

	 desc += HIY"
������������������������������������ǰ�����ɼ�����������������������������������
________________________________________________________________________________
�ӱ�  ����     ����  ��Ա                                                \n";

		  sTeam ="team/" + board->query("west");
		  entry = board->query(sTeam);
		  desc_temp = "";
		  if( entry )
		  {
			  desc_temp = desc_temp + sprintf("%4d  %12s  %4d  ",
						 to_int(board->query("west")), entry["title"], entry["this_score"] );
			  for( i = 0; i< sizeof(keys(entry["names"]));i++)
			  {
				id = board->query(sTeam+"/ids/"+sprintf("%d",i+1) );
            if(!id)continue;
				player = find_player(id);
				if( (i-1)%4==3 )
				{
					desc_temp += "\n                    ";
				}

				if( objectp(player) && userp(player) )
				{
					desc_temp += sprintf("%8s(%5d)",board->query(sTeam+"/names/"+sprintf("%d",i+1) ),player->query("sjsz/this_score") );
				}
				else
					desc_temp += sprintf("%8s(�� ��)",board->query(sTeam+"/names/"+sprintf("%d",i+1) ));

			  }
		  }
		  desc_temp += "\n";
		  desc += desc_temp;

		  desc_temp = "";
		  sTeam ="team/" + board->query("east");
		  entry = board->query(sTeam);
		  if( entry )
		  {
			desc_temp = desc_temp + sprintf("%4d  %12s  %4d  ",
					 to_int(board->query("east")), entry["title"], entry["this_score"] );
			for( i = 0; i< sizeof(keys(entry["names"]));i++)
			{
				id = board->query(sTeam+"/ids/"+sprintf("%d",i+1) );
            if(!id)continue;
				player = find_player(id);
				if( (i-1) % 4 ==3 )
				{
					desc_temp += "\n                    ";
				}
				if( objectp(player) && userp(player) )
				{
					desc_temp += sprintf("%8s(%5d)",board->query(sTeam+"/names/"+sprintf("%d",i+1) ),player->query("sjsz/this_score") );
				}
				else
					desc_temp += sprintf("%8s(�� ��)",board->query(sTeam+"/names/"+sprintf("%d",i+1) ));
			}
		  }
		  desc_temp += "\n";

	 desc += desc_temp + "
________________________________________________________________________________\n"NOR;



	 return desc;
}

int valid_leave(object player, string dir) {
        object *inv;
        int i;
        inv = all_inventory(player);

		if (!wizardp(player) && dir == "up")
			  return notify_fail("�˼����˲�û��������ȥ���\n");

		if ( dir == "out" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("�㲻�ܴ�����������뿪��\n");
                }
        }

		player->delete("sjsz/entrance");
		return ::valid_leave(player, dir);
}
