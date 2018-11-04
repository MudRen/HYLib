//Cracked by Kafei
// /d/bwdh/square.c
// ��̨
// by sdong 09/25/98

#include <ansi.h>
inherit ROOM;
#define CANGKU "/d/bwdh/sjsz/cangku.c"

string long_desc();
int do_start(string arg);
int do_stop(string arg);
int start(string host,string challenger);
int do_close_men();
int do_open_men(string arg);
void enter_sjsz();

void create()
{
	set("short", HIR"�Խ�ɽׯ��㳡"NOR);
	set("long", (: long_desc :));
	set("invalid_startroom", 1);

	set("no_fight", 1);

	set("exits", ([
		"enter" : "/d/bwdh/sjsz/square",
		"southdown": "/d/bwdh/square",
	]));


//        set("objects", ([
//                __DIR__"npc/seller" : 1,
//        ]));

	setup();
}

void init()
{
}


string long_desc()
{
  	string desc,temp;
	int nRank,i,j;

  	desc  = HIW"

		           /I______________I\\               
		         //||||||||||||||||||\\\\            
		     T\\//IIIIIIIIIIIIIIIIIIIIII\\\\/T       
	             ^^^^"+HIG"||"NOR+HIY"^^^"+HIM"[ �Խ�ɽׯ ]"NOR+HIY"^^^"+HIG"||"+HIY"^^^^         "+HIY"
		         "+HIG"||"NOR+HIY"__________________"+HIG"||"NOR+HIY"             "+HIC"
	  []___[]___[]__|[]___[]___||___[]___[]|__[]___[]___[]
	  |__________________|_|________|_|__________________|"+HIB"
             ||                                          ||
             ||                ___________               ||
             ||               @           @              ||
             ||               |           |              ||
             ||               |           |              ||
             ||               |           |              ||
             ||               |           |              ||
             ||               |           |              ||
             ||_______________|___________|______________||\n\n"NOR;

  	return desc;
}

void enter_sjsz() 
{
	 object me = this_player();
	 object *inv;
	 object *old_basket, *basket;
	 object cangku;
	 int i;

	 inv = all_inventory(me);
	 basket = allocate(sizeof(inv));
	 cangku = find_object(CANGKU);
	 if (! objectp(cangku)) {
		  cangku = load_object(CANGKU);
		  if (!objectp(cangku)) {
				message_vision("$N����� wiz: cangku not found\n", me);
				return;
		  }
	 }

	 for (i=0; i<sizeof(inv); i++) {
				basket[i] = inv[i];
				inv[i]->move(cangku);
				message_vision("$N��һ" + inv[i]->query("unit")+ inv[i]->query("name")+"����С�ˡ�\n", me);
	 }

	 old_basket = cangku->query("basket/" + me->query("id"));
	 if (arrayp(old_basket)) basket = basket + old_basket;
	 cangku->set("basket/" + me->query("id"), basket);
	 return;
}

void out_sjsz() {
	 object player = this_player();
	 object *inv, cangku, *basket;
	 int i;
	 string id;

  cangku = find_object(CANGKU);
  if (! objectp(cangku)) {
	 cangku = load_object(CANGKU);
	 if (!objectp(cangku)) {
		message_vision("$N����� wiz: cangku not found\n", player);
		return 0;
	 }
  }

  basket = cangku->query("basket/"+player->query("id"));

  if (basket) {
	 for (i=0; i<sizeof(basket); i++) {
		if (objectp(basket[i])) {
		  basket[i]->move(player);
		  message_vision("$N�������������û�һ"+
					 basket[i]->query("unit")+
					 basket[i]->query("name")+"��\n", player);
		}
	 }
	 cangku->delete("basket/"+player->query("id"));
  }
  else message_vision("������˵��$NʲôҲû����������ɱ�����̰��ร�\n", player);

  return;
}

int valid_leave(object player, string dir) {
    object *inv;
    int i;
    inv = all_inventory(player);

	if ( dir == "enter" )
	 {
		 enter_sjsz();
	 }
	 else if ( dir == "southdown" )
	 {
          for (i=0; i<sizeof(inv); i++) {
                  if (inv[i]->is_character())
                  return notify_fail("�㲻�ܴ�����������뿪��\n");
          }
		 out_sjsz();
	 }

	 player->delete("sjsz/entrance");

	 return ::valid_leave(player, dir);
}



