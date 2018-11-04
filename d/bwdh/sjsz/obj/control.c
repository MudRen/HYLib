//Cracked by Kafei
// Control panel for Group BWDH
// Apache 10/98
// changed by sdong 10/03/98 for fixing some bugs

#include <ansi.h>
inherit NPC;

int reset();
int auto_check();

#define BOARD __DIR__"npc/bwboard"
#define CANGKU "/d/bwdh/sjsz/cangku"


// I put all possible npcs at here!
string *high_npc = ({
	 "/d/biwu/ouyangfeng",
	 "/quest/menpaijob/emei/miejue",
	 "/kungfu/class/emei/zhou",
	 "/kungfu/class/gaibang/hong",
	 "/kungfu/class/huashan/feng",
	 "/kungfu/class/huashan/yue-buqun",
	 "/kungfu/class/shaolin/du-jie",
	 "/kungfu/class/shaolin/du-nan",
	 "/kungfu/class/shaolin/da-mo",
	 "/kungfu/class/wudang/zhang",
	 "/kungfu/class/xingxiu/ding",
	 "/kungfu/class/xueshan/fawang",
	 "/kungfu/class/xueshan/jiumozhi",
	 "/quest/menpaijob/shenlong/hong",
	 "/d/biwu/dongfang",
});

string *middle_npc = ({
	 "/kungfu/class/btshan/ouyangke",
	 "/kungfu/class/emei/jingxuan",
	 "/kungfu/class/gaibang/jian",
	 "/kungfu/class/shaolin/xuan-ci",
	 "/kungfu/class/shaolin/xuan-bei",
	 "/kungfu/class/shaolin/xuan-nan",
	 "/kungfu/class/shaolin/xuan-ku",
	 "/kungfu/class/wudang/mo",
	 "/kungfu/class/wudang/yu",
	 "/kungfu/class/wudang/yin",
	 "/kungfu/class/wudang/song",
	 "/kungfu/class/wudang/zhang",
	 "/kungfu/class/xingxiu/zhaixing",
	 "/kungfu/class/xuedao/shengdi",
	 "/kungfu/class/xueshan/lingzhi",
	 "/d/quanzhen/npc/hao",
	 "/d/quanzhen/npc/ma",
	 "/d/quanzhen/npc/tan",
	 "/d/quanzhen/npc/liu",
});

string *low_npc = ({
	 "/d/taishan/npc/tianmen",
	 "/kungfu/class/emei/fang",
	 "/kungfu/class/gaibang/kongkong",
	 "/kungfu/class/shaolin/hui-kong",
	 "/kungfu/class/xingxiu/azi",
	 "/kungfu/class/wudang/daotong",
	 "/kungfu/class/emei/li",
	 "/kungfu/class/emei/bei",
	 "/kungfu/class/emei/fang",
	 "/d/songshan/npc/zuo",
	 "/d/henshan/npc/moda",
	 "/d/hengshan/npc/xian",
	 "/d/qingcheng/npc/hai",
	 "/kungfu/class/shenlong/su",
	 "/kungfu/class/shenlong/wugen",
	 "/d/xingxiu/npc/gushou",
	 "/d/xingxiu/npc/boshou",
	 "/d/xingxiu/npc/haoshou",
	 "/d/xingxiu/npc/caihua",
});

string *misc_npc = ({
	 "/d/shenlong/npc/dushe",
	 "/d/shenlong/npc/fushe",
	 "/d/wudujiao/npc/baidu5",
	 "/d/wudujiao/npc/chanchu5",
	 "/d/wudujiao/npc/laohu2",
	 "/d/wudujiao/npc/qiandu5",
	 "/d/wudujiao/npc/wandu5",
	 "/d/wudujiao/npc/wolf2",
	 "/d/wudujiao/npc/wugong3",
	 "/d/wudujiao/npc/xiezi3",
	 "/d/wudujiao/npc/zhangao",
	 "/d/wudujiao/npc/zhanglang",
	 "/d/wudujiao/npc/zhizhu3",
});

string *special_weapon = ({
		  "/d/bwdh/sjsz/obj/hunterbow.c",
		  "/d/bwdh/sjsz/obj/arrow.c",
		  "/d/bwdh/sjsz/obj/dantou.c",
		  "/d/bwdh/sjsz/obj/huoyao.c",
		  "/quest/skills2/shop/shops/hammer.c",
		  "/quest/skills2/shop/shops/sword.c",  // ���콣
		  "/d/bwdh/sjsz/obj/yuxiao.c",//       : 1,  // ����
		  "/d/shaolin/obj/fumo-dao.c",//     : 1,  // ��ħ��
		  "/d/jinshe/obj/jinshe-jian.c",//  : 1,  // ���߽�
		  "/d/bwdh/sjsz/obj/eyujian.c",//      : 1,  // �����
		  "/d/bwdh/sjsz/obj/eweibian.c",//     : 1,  // ��β��
		  "/d/bwdh/sjsz/obj/xuantie-jian.c",// : 1,  // �����ؽ�
		  "/d/jinshe/obj/jinshe-zhui.c", //  : 1,  // ����׶
		  "/kungfu/class/gaibang/obj/yuzhu_zhang.c",//  : 1,  // ������
		  "/d/bwdh/sjsz/obj/qijue.c",//        : 1,  // �߾���
		  "/d/bwdh/sjsz/obj/yuchang-jian.c",// : 1,  // �㳦��
		  "/d/bwdh/sjsz/obj/zhenwu.c",//       : 1,  // ���佣
		  "/d/bwdh/sjsz/obj/dulong-bian.c", //
		  "/d/bwdh/sjsz/obj/tulong-dao.c", //
		  "/d/bwdh/sjsz/obj/fan.c", //

		  "/d/bwdh/sjsz/obj/jingun.c",//
		  "/d/bwdh/sjsz/obj/falun5.c",//
		  "/d/bwdh/sjsz/obj/qixing-jian.c", //
		  "/d/bwdh/sjsz/obj/zijin-dao.c", //
		  "/d/bwdh/sjsz/obj/heilong-bian.c ", //
		  "/d/bwdh/sjsz/obj/songwen-jian.c ", //
		  "/d/bwdh/sjsz/obj/youlong.c ", //

		  "/d/shaolin/obj/jingang-zhao.c",//: 1,  // �����
		  "/d/bwdh/sjsz/obj/wucan-yi.c",//    : 1,  // �ڲ���
		  "/kungfu/class/taohua/obj/ruanwei.c",//  : 1,  // ��⬼�
		  "/d/bwdh/sjsz/obj/xuedao.c",//       : 1,  // Ѫ��
		  "/d/bwdh/sjsz/obj/yuandao.c",//       : 1,
		  "/d/bwdh/sjsz/obj/yangdao.c",//       : 1,
});

void move_npc(object npc);
int update(int n, int result);
void sort_rank();
void clean_sjsz();
int do_judge(string arg);
int do_fire(string arg);
int do_clean(string arg);
int do_challenge(string arg);
void auto_check(int nCounts);
int do_duet(string arg);
void do_challenge(string arg);
void do_accept(string arg);
int do_goon();
int do_auto_teamup(string arg);
void move_me(object me, string place);
void nude(object obj);
void my_destruct(object obj);

void full_all(object me);
void move_me(object me, string place);

int update_room (string file);

int refresh_room (string file);
void make_weapon(object npc);
void make_npc(object room);
void refresh_sjsz();
void auto_check();
void clean_sjsz();
int do_back_stuff(string id);


void create() {
	 set_name("ȺӢ�������", ({ "da zhuchi","zhuchi","host" }));
	 set("unit", "��");
	 set("long", "����������Ӣ�۱����μ�ȺӢ���������������������ˡ�
���ֳ�һ�����ӣ����飺

����ָ��:

  teamup ���� ���1 ���2 ... ... ���19 (������ӣ�ÿ���������ˣ��������20��һ�ӡ��������Դ���ɫ)
  ����: teamup $HIW$�ɻ���$NOR$ sdong sdon sdo

  or baoming ���� ���1 ���2 ... ... ���19 (������ӣ�ÿ���������ˣ��������20��һ�ӡ��������Դ���ɫ)
  ����: baoming $HIW$�ɻ���$NOR$ sdong sdon sdo

  dismiss n (��ɢ��N��)
  kickout id (����ĳ��ҳ���)
  challenge n (��ս��N��)
  accept n(���ܵ�N����ս)
  clean id(�����ұ����¼)
  help sjsz
  \n");


/*
	 set("no_get", 1);
	 set("chat_chance", 240);
	 set("chat_msg", ({
			 (: auto_check :),
	 }) );
*/
/*
	 set("chat_chance_combat", 240);
	 set("chat_msg_combat", ({
			 (: auto_check :),
	 }) );
*/
	set("inquiry", ([
		"�Խ�ɽׯ": "�Խ�ɽׯ���������ǵ�����ʥ�ء���·Ӣ�۶�������������䡣",
		"sjsz": "�Խ�ɽׯ���������ǵ�����ʥ�ء���·Ӣ�۶�������������䡣",
		"baoming": "baoming ���� ���1 ���2 ... ... ���19 (������ӣ�ÿ���������ˣ��������20��һ�ӡ��������Դ���ɫ)",
		"join": "baoming ���� ���1 ���2 ... ... ���19 (������ӣ�ÿ���������ˣ��������20��һ�ӡ��������Դ���ɫ)",
		//"askback": "askback",
	]));

	 setup();
}

void init() {

	object me = this_player();

	//add_action("do_back_stuff", "askback");

	if( !query("bwdh") || me->query("judge") || wizardp(me) )
	{
	 add_action("do_add", "add");
	 add_action("do_add", "teamup");
	 add_action("do_discard", "dismiss");
	 add_action("do_discard", "discard");
	 add_action("do_challenge", "challenge");
	 add_action("do_accept", "accept");
	 add_action("do_fire", "kickout");
	 add_action("do_clean", "clean");
	 add_action("do_auto_teamup", "auto");

	 if( me->query("judge") || wizardp(me) )
	 {
		 add_action("do_assign", "assign");
		 add_action("do_judge", "judge");
		 add_action("do_duet", "duet");
		 add_action("do_goon", "goon");
		 add_action("do_start","start");
		 add_action("do_stop","stop");
       add_action("do_refresh","refreshsjsz");
	 }
  }
}

int do_start(string arg)
{
	object me = this_player();
	if( query("bwdh") ) return notify_fail("�����Ѿ���ʼ�ˡ�\n");
	message_vision(HIR"$N����ȺӢ�����ڿ�ʼ��\n"NOR,me);
	CHANNEL_D->do_channel(me, "chat", HIR"����ȺӢ�����ڿ�ʼ��\n"NOR);
	set("bwdh",1);
	return 1;
}

int do_stop(string arg)
{
	object me = this_player();
	if( !query("bwdh") ) return notify_fail("���仹û��ʼ�ء�\n");
	delete("bwdh");
	message_vision(HIR"����ȺӢ�������\n"NOR,me);
	CHANNEL_D->do_channel(me, "chat", HIR"����ȺӢ�������\n"NOR);
	return 1;
}

void full_all(object me)
{
	 if( !living(me) ) me->revive(0);
	 me->set("eff_jing", (int)me->query("max_jing"));
	 me->set("jing", (int)me->query("max_jing"));
	 me->set("eff_qi", (int)me->query("max_qi"));
	 me->set("qi", (int)me->query("max_qi"));
	 me->set("jingli", (int)me->query("max_jingli"));
	 me->set("neili", (int)me->query("max_neili"));
	 me->set("food", (int)me->max_food_capacity());
	 me->set("water", (int)me->max_water_capacity());
	 me->remove_all_killer();
	 me->clear_condition();
}

int do_back_stuff(string id)
{
	object *inv, cangku, *basket;
	int i;
	object player=this_player();

  cangku = find_object(CANGKU);
  if (! objectp(cangku)) {
	 cangku = load_object(CANGKU);
	 if (!objectp(cangku)) {
		message_vision("$N����� wiz: cangku not found\n", player);
		return 1;
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

  return 1;
}




void my_destruct(object obj)
{
		  int i;

		  object *inv;
		  string err;

		  if (obj && objectp(obj) ) {
								inv = all_inventory(obj);
								i = sizeof(inv);
								while(i--)
								{
										  if( inv[i] && objectp(inv[i]) && userp(inv[i]) )
										  {
											 call_out("move_me",1+random(4),inv[i],"/d/bwdh/sjsz/kantai_w1.c");
											 if( !living(inv[i]) ) inv[i]->revive(1);
											 full_all(inv[i]);
											 nude(inv[i]);
										  }
										  else
										  {
											if(inv[i] && objectp(inv[i]))
											{
												my_destruct(inv[i]);
											}
										  }
								}
					 if( userp(obj) )
					 {
						 call_out("move_me",1+random(4),obj,"/d/bwdh/sjsz/kantai_w1.c");
						 if( !living(obj) )obj->revive(1);
						 full_all(obj);
						 nude(obj);
					 }
					 else destruct(obj);
		  }
}

void nude(object obj)
{
		  int i;

		  object *inv;
		  if (obj && objectp(obj) ) {
								inv = all_inventory(obj);
								i = sizeof(inv);
								while(i--)
								{
										  if( inv[i] && objectp(inv[i]) && userp(inv[i]) )
										  {
											 call_out("move_me",1+random(4),inv[i],"/d/bwdh/sjsz/kantai_w1.c");
											 if( !living(inv[i]) ) inv[i]->revive(1);
											 full_all(inv[i]);
											 nude(inv[i]);
										  }
										  else
										  {
											if(inv[i] && objectp(inv[i]))
											{
												return my_destruct(inv[i]);
												//destruct(inv[i]);
											}
										  }
								}
		  }
}

void move_me(object me, string place)
{
	object obj;

	if( !me || !objectp(me) || !userp(me) )return;
	nude(me);
	full_all(me);

	if ( (obj = find_object(place)) && obj && objectp(obj) ) {
		me->set("sjsz/fighting",1);
		me->move(obj);
	}
	else if ( (obj = load_object(place)) && obj && objectp(obj) ) {

   	me->set("sjsz/fighting",1);
	me->move(obj);
	}

}

int update_player(object me)
{
		  object env, link_ob, obj;

		  env = environment(me);

		  // Save the data and exec the player to his/her link object.
		  me->save();

		  // First, create the new body.
		  link_ob = me->query_temp("link_ob");
		  obj = LOGIN_D->make_body(link_ob);
		  if (!obj) return 0;

		  exec(link_ob, me);
		  destruct(me);

		  // Restore new body and exec to it via enter_world in LOGIN_D
		  obj->restore();
		  LOGIN_D->enter_world(link_ob, obj, 1);

		  obj->move(env);

		  return 1;
}

int do_refresh(string arg)
{
	object ob;
	if(!arg)return notify_fail("����Ҫ����˭��\n");
	ob = find_player(arg);
	if( ob && objectp(ob) && userp(ob) && ob->query("sjsz") )
		update_player(ob);
	else return notify_fail("û����������Խ�ɽׯ�С�\n");
}



int update_room (string file)

{

		  int i;
		  object obj, *inv;
		  string err;

		  if ( (obj = find_object(file)) && objectp(obj) ) {
								inv = all_inventory(obj);
								i = sizeof(inv);
								while(i--)
								{
										  if( inv[i] && objectp(inv[i]) && userp(inv[i]) )
										  {
											 call_out("move_me",1+random(4),inv[i],"/d/bwdh/sjsz/kantai_w1.c");
											 if( !living(inv[i]) )inv[i]->revive(1);
											 full_all(inv[i]);
											 nude(inv[i]);
										  }
										  else
										  {
											if(inv[i] && objectp(inv[i]))
											{
												my_destruct(inv[i]);
											}
										  }
								}
					 my_destruct(obj);
		  }

}

/*
This will refresh a room however it won't destruct the room
*/
int refresh_room (string file)
{
		  int i;
		  object obj, *inv, me = this_player();
		  string err;


		  if (obj = find_object(file)) {
					inv = all_inventory(obj);
					i = sizeof(inv);
					while(i--)
					{
										  if( inv[i] && objectp(inv[i]) && userp(inv[i]) )
										  {
											 if( !living(inv[i]) || inv[i]->query("qi") <= 0 )
											 {
												 if( inv[i]->query("sjsz/red") )
												 {
													call_out("move_me",1+random(4),inv[i],"/d/bwdh/sjsz/west_xiangfang.c");
												 }
												 else if( inv[i]->query("sjsz/white") )
												 {
													call_out("move_me",1+random(4),inv[i],"/d/bwdh/sjsz/east_xiangfang.c");
												 }
												 if( !living(inv[i]) )inv[i]->revive(1);
												 full_all(inv[i]);
												 nude(inv[i]);
											 }
										  }
										  else
										  {
											if( inv[i] && objectp(inv[i]) && inv[i]->query("race") != "����" && inv[i]->query("id") != "pao" 
											  && inv[i]->query("id") != "dan tou" && inv[i]->query("id") != "huo yao" && inv[i]->query("id") != "box" )
												my_destruct(inv[i]);
										  }
					}
		  }

}

void make_weapon(object npc)
{
	int j, n;
	object weapon, owner;

	if(!npc || !objectp(npc) ) return;
	n = 0;
	do{
		j = random(sizeof(special_weapon));
		weapon = find_object( special_weapon[j] );
		if( weapon && objectp(weapon) )
		{
			owner = environment(weapon);
			if(owner && objectp(owner) && !userp(owner) )
				break;
		}
		weapon = new(special_weapon[j]);
		n++;
	}while(!weapon && n < 20);
	if( weapon && objectp(weapon) )
		weapon->move(npc);
}

void make_npc(object room)
{
	 object *inv,npc,ob;
	 int i,j,n,r;

	 if( !room || !objectp(room) )return;

	 n = random( 8 );

	 if( n < 1)
	 {
		do{
			j = random(sizeof(high_npc));
			npc = new(high_npc[j]);
		}
		while( !npc || !objectp(npc) );
	 }
	 else if( n < 5)
	 {
		do{
			j = random(sizeof(middle_npc));
			npc = new(middle_npc[j]);
		}
		while( !npc || !objectp(npc) );
	 }
	 else if( n < 7)
	 {
		do{
			j = random(sizeof(low_npc));
			npc = new(low_npc[j]);
		}
		while( !npc || !objectp(npc) );
	 }
	 else
	 {
		do{
			j = random(sizeof(misc_npc));
			npc = new(misc_npc[j]);
		}
		while( !npc || !objectp(npc) );
	 }

	 if (random(2) == 1) {
		 ob = new("/d/bwdh/sjsz/obj/renshen-guo");
	 }
	 else if (random(20) == 1) {
		 ob = new("/d/bwdh/sjsz/obj/bomb");
	 }
	 else
	 {
		 ob = new("/clone/drug/jinchuang");
		 ob->set_amount(random(20)+1);
	 }
	 if( ob && objectp(ob) )ob->move(npc);
	 make_weapon(npc);
	 npc->move(room);
}


void refresh_sjsz()
{
	 object room,*inv;
	 int n, r ;
	 string rm;

	 refresh_room("/d/bwdh/sjsz/wgate.c");
	 refresh_room("/d/bwdh/sjsz/wgarden.c");
	 refresh_room("/d/bwdh/sjsz/wtang.c");
	 refresh_room("/d/bwdh/sjsz/wting.c");
	 refresh_room("/d/bwdh/sjsz/wzoulan.c");
	 refresh_room("/d/bwdh/sjsz/egate.c");
	 refresh_room("/d/bwdh/sjsz/egarden.c");
	 refresh_room("/d/bwdh/sjsz/etang.c");
	 refresh_room("/d/bwdh/sjsz/eting.c");
	 refresh_room("/d/bwdh/sjsz/ezoulan.c");

	 refresh_room("/d/bwdh/sjsz/etower1.c");
	 refresh_room("/d/bwdh/sjsz/etower2.c");
	 refresh_room("/d/bwdh/sjsz/etower3.c");
	 refresh_room("/d/bwdh/sjsz/etower4.c");
	 refresh_room("/d/bwdh/sjsz/etower5.c");
	 refresh_room("/d/bwdh/sjsz/etower6.c");
	 refresh_room("/d/bwdh/sjsz/etower7.c");

	 refresh_room("/d/bwdh/sjsz/wtower1.c");
	 refresh_room("/d/bwdh/sjsz/wtower2.c");
	 refresh_room("/d/bwdh/sjsz/wtower3.c");
	 refresh_room("/d/bwdh/sjsz/wtower4.c");
	 refresh_room("/d/bwdh/sjsz/wtower5.c");
	 refresh_room("/d/bwdh/sjsz/wtower6.c");
	 refresh_room("/d/bwdh/sjsz/wtower7.c");


	 for(r=1;r<=30;r++){
		  if (r < 10)
		  {
				rm = "/d/bwdh/sjsz/room_0" + sprintf("%d", r);
				room = find_object(rm);
				if(!room) load_object(rm);
			}
		  else
		  {
				rm = "/d/bwdh/sjsz/room_" + sprintf("%d", r);
				room = find_object(rm);
				if( !room ) load_object(rm);
		  }
		  if(!room) continue;

		  refresh_room(rm);
		  inv = all_inventory(room);
		  n = sizeof(inv);
		  if ( n == 0 ) {
				make_npc(room);
		  }
	 }
	 return;
}


int auto_check()
{
	int nCounts;
	object board;
	 board =  find_object(BOARD);
	 if (!objectp(board)) {
			  board = load_object(BOARD);
			  if (!objectp(board))
					return 0;
	 }

	nCounts = board->query("counts");

	if(nCounts <=0 )
	{
	 if( board->query("west") && board->query("east") )
		{
			call_out("auto_check", 10);
			call_out("clean_sjsz",20);
			do_judge("");
			return 0;
		}
	 else return 1;
	}

	nCounts--;
	board->set("counts",nCounts);
	remove_call_out("auto_check");
	call_out("auto_check",60*3);

	refresh_sjsz();
}

int do_goon()
{
	object me = this_player();
	auto_check();
	return 1;
}


void clean_sjsz()
{
	int i;
	object room;

	for ( i = 1; i <= 30; i++) {
			if (i < 10)
			{
			 update_room("/d/bwdh/sjsz/room_0" + sprintf("%d", i));
			 room = find_object("/d/bwdh/sjsz/room_0" + sprintf("%d", i));
			}
			else
			{
			 update_room("/d/bwdh/sjsz/room_" + sprintf("%d", i));
			 room = find_object("/d/bwdh/sjsz/room_" + sprintf("%d", i));
			}

			if( room && objectp(room) )
					 destruct(room);
	}
	update_room("/d/bwdh/sjsz/wgate.c");
	update_room("/d/bwdh/sjsz/wgarden.c");
	update_room("/d/bwdh/sjsz/wtang.c");
	update_room("/d/bwdh/sjsz/wting.c");
	update_room("/d/bwdh/sjsz/wzoulan.c");
	update_room("/d/bwdh/sjsz/egate.c");
	update_room("/d/bwdh/sjsz/egarden.c");
	update_room("/d/bwdh/sjsz/etang.c");
	update_room("/d/bwdh/sjsz/eting.c");
	update_room("/d/bwdh/sjsz/ezoulan.c");
	update_room("/d/bwdh/sjsz/west_xiangfang.c");
	update_room("/d/bwdh/sjsz/east_xiangfang.c");
	 update_room("/d/bwdh/sjsz/etower1.c");
	 update_room("/d/bwdh/sjsz/etower2.c");
	 update_room("/d/bwdh/sjsz/etower3.c");
	 update_room("/d/bwdh/sjsz/etower4.c");
	 update_room("/d/bwdh/sjsz/etower5.c");
	 update_room("/d/bwdh/sjsz/etower6.c");
	 update_room("/d/bwdh/sjsz/etower7.c");

	 update_room("/d/bwdh/sjsz/wtower1.c");
	 update_room("/d/bwdh/sjsz/wtower2.c");
	 update_room("/d/bwdh/sjsz/wtower3.c");
	 update_room("/d/bwdh/sjsz/wtower4.c");
	 update_room("/d/bwdh/sjsz/wtower5.c");
	 update_room("/d/bwdh/sjsz/wtower6.c");
	 update_room("/d/bwdh/sjsz/wtower7.c");

}

int do_duet(string arg)
{
	 object me = this_player(), player;
	 object room, ob, npc, env, *inv;
	 string cmd;
	 int n, total, i, j;
	 object board;

	 if( !arg || sscanf(arg, "%s", cmd) != 1)
		  return notify_fail("ָ�����\n");

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
			  board = load_object(BOARD);
			  if (!objectp(board))
					return notify_fail("�Ҳ����������ɼ��档\n");
	 }

	 switch (cmd) {
	 case "start" :
						  if( !board->query("east") || !board->query("east") )
							  return notify_fail("��������û�б�����\n");
						  call_out("auto_check",60*4);
						  room = find_object("/d/bwdh/sjsz/wtang");
						  if(!room)room = load_object("/d/bwdh/sjsz/wtang");
						  room->set("flag",1);
						  room->set("team_name",board->query("westname") );
						  room = find_object("/d/bwdh/sjsz/etang");
						  if(!room)room = load_object("/d/bwdh/sjsz/etang");
						  room->set("flag",1);
						  room->set("team_name", board->query("eastname") );

						  if( wizardp(me) || me->query("judge") )
						  {
								message_vision("$N����������ʼ��\n", me);
								CHANNEL_D->do_channel(me, "chat", board->query("westname")+"�����ڿ�ʼ��"+board->query("eastname")+"�Ӿ�����\n" );
						  }

						  board->set("counts",5);
						  break;
	 case "clean" :
						 clean_sjsz();
						 board->delete("east");
						 board->delete("west");
						 board->delete("eastname");
						 board->delete("westname");
						 break;
	 default : return notify_fail("ָ�����\n");
				  break;
	 }
	 return 1;
}

int do_judge(string arg) {
	 object ob = this_object(), rum_ob;
	 string side,msg;
	 int east, west, n;
	 object board;
	 mapping entryA, entryB;
	 int i, scoreA, scoreB;

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
			  board = load_object(BOARD);
			  if (!objectp(board))
					return 1;//notify_fail("�Ҳ����������ɼ��档\n");
	 }

	 if( !board->query("east") || !board->query("east") )
		  return 1;//notify_fail("��������û�б�����\n");

	 if( !arg || arg=="" )
	 {
		 entryA = board->query("team/" + board->query("east"));
		 if ( !entryA )return notify_fail("�Ҳ������ӡ�\n");
		 entryB = board->query("team/" + board->query("west"));
		 if ( !entryB )return notify_fail("�Ҳ������ӡ�\n");
		 scoreA = to_int(entryA["this_score"]);
		 scoreB = to_int(entryB["this_score"]);

		 if( scoreA > scoreB ) side = "east";
		 else if( scoreA == scoreB ) side = "tie";
		 else side = "west";
	 }

	 msg = "������������������";

	 switch(side) {
	 case "east" :   east = 2; west = 0;
						  //if(objectp(me)) message_vision("$N�ж���ʤ��\n", me);
						  msg += board->query("eastname") + "ʤ" + board->query("westname");
						  break;
	 case "west" :   east = 0; west = 2;
						  //if(objectp(me))message_vision("$N������ʤ��\n", me);
						  msg += board->query("westname") + "ʤ" + board->query("eastname");
						  break;
	 case "tie"  :   east = 1; west = 1;
						  //if(objectp(me))message_vision("$N�б���ƽ��\n", me);
						  msg += board->query("eastname") + "ƽ" + board->query("westname");
						  break;
	 default : return 1;//notify_fail("ָ�����\n");
	 }
	 msg += "\n";

	 rum_ob = load_object("/d/huashan/npc/referee");
	 if(objectp(rum_ob))
	 {
		 CHANNEL_D->do_channel(rum_ob, "chat", msg );
		 destruct(rum_ob);
	 }

	 n = to_int(board->query("east"));
	 call_out("update",1,n, east);
	 n = to_int(board->query("west"));
	 call_out("update",1,n, west);

	 board->delete("east");
	 board->delete("west");
	 board->delete("eastname");
	 board->delete("westname");

	 call_out("sort_rank", 18);
	 call_out( "do_duet", 20, "clean" );

	 return 1;
}

int update(int n, int result) {
	 object board, player;
	 mapping entry;
	 int i, score;
	 string id;

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
		  board = load_object(BOARD);
		  if (!objectp(board))
				return 1;
	 }

	 entry = board->query("team/" + sprintf("%d", n));
	 if( !entry )return 1;

	 score = (int)(entry["score"]);
	 score = score + result;
	 entry["score"] = score;

	 switch(result) {
	 case 2 :
				 entry["win"] = entry["win"] + 1;
				 break;
	 case 1 :
				 entry["tie"] = entry["tie"] + 1;

	 case 0 :
				 entry["lose"] = entry["lose"] + 1;
	 default : break;
	 }

	 board->set("team/" + sprintf("%d", n),entry);


	for ( i = 0; i < sizeof(board->query( "team/" + sprintf("%d", n) + "/ids")); i++) {
								id = board->query( "team/" + sprintf("%d", n) + "/ids/" + sprintf("%d", i+1) );
								if( !id ) continue;
								player = find_player(id);
								if ( !player || !objectp(player) || !userp(player) )
								{
									//write("�Ҳ������ " + board->query( "team/" + sprintf("%d", n) + "/names/" + sprintf("%d", i+1) ) + "\n");
									continue;
								}

								score = player->query("sjsz/this_score")/5;
								if( score > 1500 ) score = 1500;
								player->add("combat_exp",score);

								if( result == 2)
								{
									player->add("sjsz/win",1);

									if(player->query("sjsz/this_score") > 0)
									{
										player->add("combat_exp",1800);
										player->set("potential",player->query("max_potential")*2/3 + random( player->query("max_potential")/3 ) );
									}
								}
								else if( result == 1)
								{
									player->add("sjsz/tie",1);
									if(player->query("sjsz/this_score") > 0)
									{
										player->add("combat_exp",1000);
										player->set("potential",player->query("max_potential")/2 + random( player->query("max_potential")/2 ) );
									}
								}
								else
								{
									player->add("sjsz/lose",1);
									if(player->query("sjsz/this_score") > 0)
									{
										player->add("combat_exp",800);
										player->set("potential",player->query("max_potential")/3 + random( player->query("max_potential")/2 ) );
									}
								}

								player->delete("sjsz/entrance");
								player->delete("sjsz/this_score");
								player->delete("sjsz/this_flag");
								player->delete("sjsz/this_exp");
								player->delete("sjsz/white");
								player->delete("sjsz/red");
								if( player->query("sjsz/white") )
								 call_out("move_me",1+random(16),player,"/d/bwdh/sjsz/kantai_e1.c");
								else call_out("move_me",1+random(16),player,"/d/bwdh/sjsz/kantai_w1.c");

								if( !living(player) )player->revive(1);
								full_all(player);
								nude(player);
message_vision(HIW"������ͻȻ���֣�˵����ʱ���ѵ����������˳�ɽׯ��˵�꣬һ��һ�ƣ�$N�;������Ƽ���һ�����\n",player);
	}


	 return 1;
}

void sort_rank()
{
	 object board;
	 mapping entry, entryB;
	 int i, score, scoreB, win, winB, tie, tieB, lose, loseB, exchange, j;


	 board =  find_object(BOARD);
	 if (!objectp(board)) {
			  board = load_object(BOARD);
			  if (!objectp(board))
					return ;
	 }


	 for(i = 1; i < sizeof(board->query("team")); i++) {
		  entry = board->query("team/" + sprintf("%d", i));
		  score = to_int(entry["score"]);
		  win = to_int(entry["win"]);
		  tie = to_int(entry["tie"]);
		  lose = to_int(entry["lose"]);
		  for ( j = i + 1; j <= sizeof(board->query("team")); j++) {
				entryB = board->query("team/" + sprintf("%d", j));
				scoreB = to_int(entryB["score"]);
				winB = to_int(entryB["win"]);
				tieB = to_int(entryB["tie"]);
				loseB = to_int(entryB["lose"]);
				exchange = 0;
				if (score < scoreB) exchange = 1;
				if( (score == scoreB) && (win < winB) ) exchange = 1;
				if( (score == scoreB) && (win = winB) && (tie < tieB) ) exchange = 1;
				if( (score == scoreB) && (win = winB) && (tie = tieB) && (lose > loseB) ) exchange = 1;
				if (exchange) {
					 board->set("team/" + sprintf("%d", i),entryB);
					 board->set("team/" + sprintf("%d", j),entry);
				}
		  }
	 }
	 return;
}

int do_assign(string arg) {
	 object me = this_player(), player, board, ob = this_object();
	 mapping entry;
	 string side,id,s;
	 int n, total, i;

	 if( sscanf(arg, "%d %s", n, side) != 2)
		  return notify_fail("ָ�����\n");

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
		  board = load_object(BOARD);
		  if (!objectp(board))
				return notify_fail("�Ҳ����������ɼ��档\n");
	 }

	 n = to_int(arg);

	 total = sizeof(board->query("team"));
	 if ( (n < 1) || (n > total) )
		  return notify_fail("�Ҳ�������ӡ�\n");
	 s = "team/" + sprintf("%d", n);
	 entry = board->query(s);

	for ( i = 0; i < sizeof(board->query( s + "/ids")); i++) {
		id = board->query( s + "/ids/" + sprintf("%d", i+1) );
		if( !id ) return notify_fail("�Ҳ������ " + id + "\n");
		player = find_player(id);
		if (!player || !objectp(player) || !userp(player))
			return notify_fail("�Ҳ������ " + id + "\n");
	}

	 if( !me->query("sjsz/leader") && !wizardp(me) )
		  return notify_fail("ֻ�жӳ����������\n");


	 switch(side) {
	 case "east" :

						for ( i = 0; i < sizeof(board->query( s + "/ids")); i++) {
								id = board->query( s + "/ids/" + sprintf("%d", i+1) );
								if( !id ) continue;
								player = find_player(id);
								if (!player || !objectp(player) || !userp(player))
								{
										  //write("�Ҳ������ " + id + "\n");
										  continue;
								}

								player->set("sjsz/entrance", "east");
								player->delete("sjsz/this_score");
								player->delete("sjsz/this_flag");
								player->delete("sjsz/this_exp");
								call_out("move_me",3+random(10),player,"/d/bwdh/sjsz/east_xiangfang.c");
								if( !living(player) ) player->revive(1);
								full_all(player);
								//message_vision("����������һ�ư�$N�ͽ��Խ�ɽׯ��\n",player);
						  }

						  //message_vision("$N�����" + chinese_number(n) + "�ӴӶ���̨�糡��\n", me);
						  board->set( "eastname", entry["title"] );
						  board->set("east",n);
						  entry["this_score"] = 0;
						  board->set(s,entry);
						  return 1;
						  break;
	 case "west" :

						for ( i = 0; i < sizeof(board->query( s + "/ids")); i++) {
								id = board->query( s + "/ids/" + sprintf("%d", i+1) );
								if( !id ) continue;
								player = find_player(id);
								if (!player || !objectp(player) || !userp(player))
								{
										  //write("�Ҳ������ " + id + "\n");
										  continue;
								}

								player->set("sjsz/entrance", "west");
								player->delete("sjsz/this_score");
								player->delete("sjsz/this_flag");
								player->delete("sjsz/this_exp");
								call_out("move_me",3+random(10),player,"/d/bwdh/sjsz/west_xiangfang.c");
								if( !living(player) ) player->revive(1);
								full_all(player);
								//message_vision("����������һ�ư�$N�ͽ��Խ�ɽׯ��\n",player);
						  }

						  //message_vision("$N�����" + chinese_number(n) + "�Ӵ�����̨�糡��\n", me);
						  board->set( "westname", entry["title"] );
						  board->set("west",n);
						  entry["this_score"] = 0;
						  board->set(s,entry);
						  return 1;
						  break;
	 default:        return notify_fail("ָ�����\n");
						  break;
	 }

	 board->save();

	 return 1;
}

int do_discard(string arg) {
	 object me = this_player(), board, player;
	 mapping entry;
	 int n, i, total;
	 string id;

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
		  board = load_object(BOARD);
		  if (!objectp(board))
				return notify_fail("�Ҳ����������ɼ��档\n");
	 }

	 if( !me->query("sjsz/leader") && !wizardp(me) )
		  return notify_fail("ֻ�жӳ����������\n");

	 n = to_int(arg);
	 total = sizeof(board->query("team"));
	 if ( (n < 1) || (n > total) )
		  return notify_fail("�Ҳ�������ӡ�\n");

	 entry = board->query("team/" + sprintf("%d", n));

	 if( entry["title"] != me->query("sjsz/leader") && !wizardp(me) )
		return notify_fail("ֻ�б��Ӷӳ����������\n");



	 for ( i = 0; i < sizeof(board->query("team/" + sprintf("%d", n) + "/ids")); i++) {
				id = board->query( "team/" + sprintf("%d", n) + "/ids/" + sprintf("%d", i+1) );
				if(!id)continue;
				player = find_player(id);
				if (!player || !objectp(player) || !userp(player))
					  write("�Ҳ������ " + id + "\n");
				else
					player->delete("sjsz");
	 }


	 message_vision("$N������ɢ��" + chinese_number(n) + "�ӣ�"+entry["title"]+"��\n", me);
	 board->delete("team/" + sprintf("%d", n));
	 for (i = n; i < total; i++) {
		  entry = board->query("team/" + sprintf("%d", i+1));
		  board->set("team/" + sprintf("%d", i), entry);
	 }

	 board->delete("team/" + sprintf("%d", total));
	 board->save();
	 return 1;
}


int do_add(string arg) {
	 object me = this_player(), board, player,here;
	 string *user = ({ "", "", "", "", "", "", "", "", "","", "", "", "", "", "", "", "", "","", "", "", "", "", "", "", "", "","", "", "", "", "", "", "", "", "","", "", "", "", "", "", "", "", "","", "", "", "", "", "", "", "", "" });
	 string title;
	 string msg = "";
	 int total, i,j,exp;

	 if(!arg)return notify_fail("Usage: teamup group_title user1 user2 user3 user4 user5 user6 ... user20\n3 to 20 players per team\n");

	 if( me->query("combat_exp") < 500000 )return notify_fail("������ŭ�������书��ô����䵱�ӳ���\n");

	 if(
		sscanf(arg, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4], user[5],user[6],user[7],user[8],user[9],user[10],user[11],user[12],user[13],user[14],user[15],user[16],user[17],user[18],user[19] ) != 21 &&
		sscanf(arg, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4], user[5],user[6],user[7],user[8],user[9],user[10],user[11],user[12],user[13],user[14],user[15],user[16],user[17],user[18] ) != 20 &&
		sscanf(arg, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4], user[5],user[6],user[7],user[8],user[9],user[10],user[11],user[12],user[13],user[14],user[15],user[16],user[17] ) != 19 &&
		sscanf(arg, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4], user[5],user[6],user[7],user[8],user[9],user[10],user[11],user[12],user[13],user[14],user[15],user[16] ) != 18 &&
		sscanf(arg, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4], user[5],user[6],user[7],user[8],user[9],user[10],user[11],user[12],user[13],user[14],user[15] ) != 17 &&
		sscanf(arg, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4], user[5],user[6],user[7],user[8],user[9],user[10],user[11],user[12],user[13],user[14]) != 16 &&
		sscanf(arg, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4], user[5],user[6],user[7],user[8],user[9],user[10],user[11],user[12],user[13]) != 15 &&
		sscanf(arg, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4], user[5],user[6],user[7],user[8],user[9],user[10],user[11],user[12]) != 14 &&
		sscanf(arg, "%s %s %s %s %s %s %s %s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4], user[5],user[6],user[7],user[8],user[9],user[10],user[11]) != 13 &&
		sscanf(arg, "%s %s %s %s %s %s %s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4], user[5],user[6],user[7],user[8],user[9],user[10]) != 12 &&
		sscanf(arg, "%s %s %s %s %s %s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4], user[5],user[6],user[7],user[8],user[9]) != 11 &&
		sscanf(arg, "%s %s %s %s %s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4], user[5],user[6],user[7],user[8]) != 10 &&
		sscanf(arg, "%s %s %s %s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4], user[5],user[6],user[7]) != 9 &&
		sscanf(arg, "%s %s %s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4], user[5],user[6]) != 8 &&
		sscanf(arg, "%s %s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4], user[5]) != 7 &&
		sscanf(arg, "%s %s %s %s %s %s", title, user[0], user[1], user[2], user[3], user[4]) != 6 &&
		sscanf(arg, "%s %s %s %s %s", title, user[0], user[1], user[2], user[3]) != 5 &&
		sscanf(arg, "%s %s %s %s", title, user[0], user[1], user[2] ) != 4 )
		  return notify_fail("Usage: teamup group_title user1 user2 user3 user4 user5 user6 ... user20\n3 to 20 players per team\n");


	 board =  find_object(BOARD);
	 if (!objectp(board)) {
		  board = load_object(BOARD);
		  if (!objectp(board))
				return notify_fail("�Ҳ����������ɼ��档\n");
	 }

	 here = environment(me);

	  title = replace_string(title, "$BLK$", BLK);
	  title = replace_string(title, "$RED$", RED);
	  title = replace_string(title, "$GRN$", GRN);
	  title = replace_string(title, "$YEL$", YEL);
	  title = replace_string(title, "$BLU$", BLU);
	  title = replace_string(title, "$MAG$", MAG);
	  title = replace_string(title, "$CYN$", CYN);
	  title = replace_string(title, "$WHT$", WHT);
	  title = replace_string(title, "$HIR$", HIR);
	  title = replace_string(title, "$HIG$", HIG);
	  title = replace_string(title, "$HIY$", HIY);
	  title = replace_string(title, "$HIB$", HIB);
	  title = replace_string(title, "$HIM$", HIM);
	  title = replace_string(title, "$HIC$", HIC);
	  title = replace_string(title, "$HIW$", HIW);
	  title = replace_string(title, "$NOR$", NOR);


	 for(i = 0; i < 20; i++) {
		  if( user[i] == "" )break;
		  player = present(user[i], here);
		  if( !player && wizardp(me) )
			  player = find_player(user[i]);
		  if (!player || !objectp(player) || !userp(player))
			  return notify_fail("�Ҳ������ " + user[i] + "\n");
		  if( player->query("sjsz/team_name") )
			  return notify_fail(player->query("name") + "�Ѿ���" + player->query("sjsz/team_name")+"���ˡ�\n");
		  if( player->query("combat_exp")<80000 ) return notify_fail("������ŭ����"+player->query("name")+"�书��ô��������Խ�ɽׯ�轣��\n");
		  for(j=0;j<i;j++)
		  {
			 if(user[j] == user[i])
				return notify_fail(player->query("name") + "�Ѿ���" + player->query("sjsz/team_name")+"���ˡ�\n");
		  }
	 }

	 total = sizeof(board->query("team"));
	 total++;
	 board->set("team/" + sprintf("%d",total)+"/title" , title);
	 board->set("team/" + sprintf("%d",total)+"/score" , 0);
	 board->set("team/" + sprintf("%d",total)+"/win" , 0);
	 board->set("team/" + sprintf("%d",total)+"/tie" , 0);
	 board->set("team/" + sprintf("%d",total)+"/lose" , 0);

	 exp = 0;
	 for(i = 0; i < 20; i++) {
		  if( user[i] == "" )break;
		  player = present(user[i], here);
		  if( !player && wizardp(me) )
			  player = find_player(user[i]);
		  if (!player || !objectp(player) || !userp(player))
				continue;

		  board->set("team/" + sprintf("%d",total)+"/ids/"+sprintf("%d",i+1), player->query("id"));
		  board->set("team/" + sprintf("%d",total)+"/names/"+sprintf("%d",i+1), player->query("name"));

		  player->delete("sjsz");
		  player->set("sjsz/team_name",title);
		  player->set_temp("apply/short", ({HIW""+player->query("sjsz/team_name")+"  "NOR+player->name()+"("+player->query("id")+")"}));
		  exp += player->query("combat_exp");
		  msg = msg + player->query("name") + " ";
	 }

	 if( exp < 1000000 )
	 {
		  board->delete("team/" + sprintf("%d",total));
		  for(i = 0; i < 20; i++)
		  {
			  if( user[i] == "" )break;
			  player = find_player(user[i]);
			  if (!player || !objectp(player) || !userp(player))
				continue;
			  player->delete("sjsz");
			  player->delete("apply/short");
		  }
		  return notify_fail("������ŭ���������书��ô��������Խ�ɽׯ�轣��\n");
	 }

	 board->set("team/" + sprintf("%d",total)+"/exp", exp);

	 present(user[0],here)->set("sjsz/leader",title);
	 /*board->set("team/" + sprintf("%d",total)+"/leader", me->query("id"));*/
	 board->set("team/" + sprintf("%d",total)+"/leader", user[0] );

	 board->save();
	 message_vision("$N����" + msg + "Ϊ��" + chinese_number(total) + "�ӣ�" + title + "\n", me);
	 return 1;
}


int do_fire(string arg) {
	 mapping entry;
	 int i, j,k,exp;
	 string title,id;
	 object me = this_player(), board, player;

	 if(!arg)
		  return notify_fail("Usage: fire player\n");

	 if( !me->query("sjsz/leader") && !wizardp(me) )
		  return notify_fail("ֻ�жӳ����������\n");

	 player = find_player(arg);
	 if(!player)return notify_fail("�Ҳ���������\n");

	 if(player == me ) return notify_fail("����Ϊ�ӳ��������Լ������ǽ�ɢ(dismiss)�������ˡ�\n");

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
		  board = load_object(BOARD);
		  if (!objectp(board))
				return notify_fail("�Ҳ����������ɼ��档\n");
	 }


	 for(i = 1; i <= sizeof(board->query("team")); i++) {
		  entry = board->query("team/" + sprintf("%d", i));
		  title = entry["title"];
		  if( title == me->query("sjsz/team_name") )
		  {
			for ( j = 0; j < sizeof(entry); j++) {
				id= board->query("team/" + sprintf("%d", i) + "/ids/" + sprintf("%d", j+1) );
				if( id != arg )continue;
				player = find_player(id);
				if( !player || !userp(player))
					  return notify_fail("�Ҳ������ " + board->query("team/" + sprintf("%d", i) + "/names/" + sprintf("%d", j+1) ) + "\n");
				player->delete("sjsz");
				for ( k = j; k < sizeof(keys(entry))-1; k++) {
					board->set(("team/" + sprintf("%d", i) + "/names/" + sprintf("%d", k+1) ),
						board->query("team/" + sprintf("%d", i) + "/names/" + sprintf("%d", k+2) ) );
					board->set( ("team/" + sprintf("%d", i) + "/ids/" + sprintf("%d", k+1) ),
						board->query("team/" + sprintf("%d", i) + "/ids/" + sprintf("%d", k+2) ) );
				}
				board->delete("team/" + sprintf("%d", i) + "/ids/" + sprintf("%d", k+2) );

				exp = board->query("team/"+ sprintf("%d", i) + "/exp");
				exp -= player->query("combat_exp");
				exp = board->set("team/"+ sprintf("%d", i) + "/exp",exp);

				if(player!=me)
					message_vision("$N��$n������"+title+"��\n",me,player);
				else message_vision("$N���Լ�������"+title+"��\n",me);
				player->delete("sjsz");
				board->save();
				return 1;
			}
		 }
	 }

	 return notify_fail("�����Ҳ����Լ�����\n");
}


int do_clean(string arg) {
	 mapping entry;
	 int i, j,k,exp;
	 string title,id;
	 object me = this_player(), board, player;

	 if(!arg)
		  return notify_fail("Usage: clean player to clean score\n");

	 if( do_fire(arg) == 1 ) return 1;

	 player = find_player(arg);
	 if(!player)return notify_fail("�Ҳ���������\n");

	 if( !me->query("sjsz/leader") && me != player  && !wizardp(me) )
		  return notify_fail("ֻ�жӳ����Լ����������\n");

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
		  board = load_object(BOARD);
		  if (!objectp(board))
				return notify_fail("�Ҳ����������ɼ��档\n");
	 }


	 for(i = 1; i <= sizeof(board->query("team")); i++) {
		  entry = board->query("team/" + sprintf("%d", i));
		  title = entry["title"];

			for ( j = 0; j < sizeof(entry); j++) {
				id= board->query("team/" + sprintf("%d", i) + "/ids/" + sprintf("%d", j+1) );
				if( id != arg )continue;
				player = find_player(id);
				if( !player || !userp(player))
					  return notify_fail("�Ҳ������ " + board->query("team/" + sprintf("%d", i) + "/names/" + sprintf("%d", j+1) ) + "\n");
				player->delete("sjsz");
				for ( k = j; k < sizeof(keys(entry))-1; k++) {
					board->set(("team/" + sprintf("%d", i) + "/names/" + sprintf("%d", k+1) ),
						board->query("team/" + sprintf("%d", i) + "/names/" + sprintf("%d", k+2) ) );
					board->set( ("team/" + sprintf("%d", i) + "/ids/" + sprintf("%d", k+1) ),
						board->query("team/" + sprintf("%d", i) + "/ids/" + sprintf("%d", k+2) ) );
				}
				board->delete("team/" + sprintf("%d", i) + "/ids/" + sprintf("%d", k+2) );

				exp = board->query("team/"+ sprintf("%d", i) + "/exp");
				exp -= player->query("combat_exp");
				board->set("team/"+ sprintf("%d", i) + "/exp",exp);

				if(player!=me)
					message_vision("$N��$n������"+title+"��\n",me,player);
				else message_vision("$N���Լ�������"+title+"��\n",me);
				board->save();
			}
	 }

	 player->delete("sjsz");

	 return notify_fail(arg+" ����ɼ������.\n");
}

int do_challenge(string arg) {
	 object me = this_player(), player, board,target;
	 mapping entry;
	 string id,s, my_title, target_title;
	 int n, total, i, j, my_exp, target_exp,gap_exp;

	 if( !arg || sscanf(arg, "%d", n) != 1)
		  return notify_fail("ָ�����(challenge n(to challenge team n)\n");

	 if( me->query("sjsz/challenging") ==n )return notify_fail("���Ѿ���˶���ս�ˣ�\n");

	 if( !me->query("sjsz/leader") )
		  return notify_fail("ֻ�жӳ����������\n");

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
		  board = load_object(BOARD);
		  if (!objectp(board))
				return notify_fail("�Ҳ����������ɼ��档\n");
	 }

	 s = "team/" + sprintf("%d", n);
	 entry = board->query(s);
	 if ( (n < 1) || !entry )
		  return notify_fail("�Ҳ�������ӡ�\n");

	target_title = entry["title"];
	target_exp = entry["exp"];

	for ( i = 0; i < sizeof(board->query( s + "/ids")); i++) {
		id = board->query( s + "/ids/" + sprintf("%d", i+1) );
		if( !id ) return notify_fail("�Ҳ������ " + id + "\n");
		player = find_player(id);
		if (!player || !objectp(player) || !userp(player))
			return notify_fail("�Ҳ������ " + id + "\n");
	}

	my_title = me->query("sjsz/team_name");
	if( i+1 == n || target_title == my_title) return notify_fail("�Լ���ս�Լ���\n");


  for ( i = 0; i < sizeof(board->query( "team" ) ); i++) {
		if( board->query( "team/" + sprintf("%d", i+1) + "/title") == my_title )
		{
			if( i+1 == n || target_title == my_title) return notify_fail("�Լ���ս�Լ���\n");

			my_exp = board->query( "team/" + sprintf("%d", i+1)  + "/exp");
			if( my_exp > target_exp ) gap_exp = my_exp - target_exp;
			else gap_exp = target_exp - my_exp;
			if( gap_exp/10 / ((my_exp + target_exp)/1000) > 20 )
				return notify_fail("ɽׯ����ҡͷ�����������书���̫�󣬲��ײ��ף�n");

						for ( j = 0; j < sizeof(board->query( "team/" + sprintf("%d", i+1) + "/ids")); j++) {
								id = board->query( "team/" + sprintf("%d", i+1) + "/ids/" + sprintf("%d", j+1) );
								if( !id ) continue;
								player = find_player(id);
								if (!player || !objectp(player) || !userp(player))
								{
										  return notify_fail("�Ҳ������ " + id + "\n");
								}
					  }
			break;
		}
  }

  target = find_player( board->query( "team/" + sprintf("%d", n) + "/leader" ) );
  if( objectp(target))
  {
	  message_vision("$N����"+my_title+"����$n��"+target_title+"�ӷ�����ս��"+HIR"�����Ŷ��ӱ����ǿ�����տɸ��뱾����һ��ս����\n"NOR,me,target);
	  me->set("sjsz/challenging",n);
	  target->set("sjsz/challenger",i+1);
  }

  return 1;
}

void do_accept(string arg) {
	 object me = this_player(), player, board,target;
	 mapping entry;
	 string id,s, my_title, target_title;
	 int n, total, i, j;

	 if( !arg )
		  return notify_fail("ָ�����\naccept n(to accept team n challenging)\n");
	 n = to_int(arg);

	 if( !me->query("sjsz/leader") )
		  return notify_fail("ֻ�жӳ�������������ս��\n");

	 if( me->query("sjsz/challenger") !=n )return notify_fail("�˶�Ŀǰ��û��������ս��\n");

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
		  board = load_object(BOARD);
		  if (!objectp(board))
				return notify_fail("�Ҳ����������ɼ��档\n");
	 }

	 if( board->query("west") && board->query("east") )return notify_fail("ɽׯ���˱�Ǹ���������������Ѿ�ռ�ñ��䳡�ˡ����Ժ���������\n");

	 s = "team/" + sprintf("%d", n);

	 entry = board->query(s);
	 if ( (n < 1) || !entry )
		  return notify_fail("�Ҳ�������ӡ�\n");

	for ( i = 0; i < sizeof(board->query( s + "/ids")); i++) {
		id = board->query( s + "/ids/" + sprintf("%d", i+1) );
		if( !id ) return notify_fail("�Ҳ������ " + id + "\n");
		player = find_player(id);
		if (!player || !objectp(player) || !userp(player))
			return notify_fail("�Ҳ������ " + id + "\n");
	}

	target_title = entry["title"];
	my_title = me->query("sjsz/team_name");

  for ( i = 0; i < sizeof(board->query( "team" ) ); i++) {
		if( board->query( "team/" + sprintf("%d", i+1)  + "/title") == my_title )
		{
						for ( j = 0; j < sizeof(board->query( "team/" + sprintf("%d", i+1) + "/ids")); j++) {
								id = board->query( "team/" + sprintf("%d", i+1) + "/ids/" + sprintf("%d", j+1) );
								if( !id ) return notify_fail("�Ҳ������ " + id + "\n");
								player = find_player(id);
								if (!player || !objectp(player) || !userp(player))
								{
										  return notify_fail("�Ҳ������ " + id + "\n");
								}
					  }
					  break;
		}
  }

  target = find_player( board->query( "team/" + sprintf("%d", n) + "/leader" ) );
  if( objectp(target))
  {
	  message_vision( my_title+"��$NӦ����"+target_title+"��$n�ȵ���"+HIR"��"+RANK_D->query_rude(target)+"��"+RANK_D->query_self(me)+HIR"������㣿���ձ����������һ��ս�������ǣ����һ��ϰ�����\n"NOR,me,target);
  }

	start_busy(20);
	call_out( "do_duet", 5, "start" );
  clean_sjsz();
  refresh_sjsz();

  call_out( "do_assign",1, sprintf("%d west",i+1) );
  message_vision( HIG"$N�����"+chinese_number(i+1)+ "��"+my_title+"���������볡\n"NOR,me);

  call_out( "do_assign",3, sprintf("%d east",n)  ) ;
  message_vision( HIG"$N�����"+chinese_number(n)+ "��"+target_title+"���ɶ����볡\n"NOR,target);

  
  CHANNEL_D->do_channel(this_object(), "chat", me->query("name")+"����"+my_title+"�����ڿ�ʼ��"+target->query("name")+"�����"+target_title+"�Ӿ�����\n" );

  target->delete("sjsz/challenging");
  me->delete("sjsz/challenger");
}

int do_auto_teamup(string arg) {
	 object me = this_player(), board, player;
	 string *user = ({ "", "", "", "", "", "", "", "", "","", "", "", "", "", "", "", "", "","", "", "", "", "", "", "", "", "","", "", "", "", "", "", "", "", "","", "", "", "", "", "", "", "", "","", "", "", "", "", "", "", "", "" });
	 string title;
	 string msg = "";
	 int ppl=0, i,j, exp, exp1,exp2,sum_exp,top_exp,sec_exp;
     object *inv, here = environment(me);
	 string team1,team2,top_id,sec_id;

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
		  board = load_object(BOARD);
		  if (!objectp(board))
				return notify_fail("�Ҳ����������ɼ��档\n");
	 }


	 if( this_object()->is_busy() )return notify_fail("�����˵�������æ���أ�\n") ;

	 if( board->query("west") && board->query("east") )return notify_fail("ɽׯ���˱�Ǹ���������������Ѿ�ռ�ñ��䳡�ˡ����Ժ���������\n");

	 if( me->query("combat_exp") < 500000 )return notify_fail("������ŭ�������书��ô�����ָ�����ӣ�\n");

	 inv = all_inventory(here);
	 i = sizeof(inv);

	 exp=0;
	 top_exp=0;
	 sec_exp=0;
	 while(i)
	{
		 i--;
	  if( inv[i] && objectp(inv[i]) && living(inv[i]) && userp(inv[i]) && inv[i]->query("combat_exp") > 80000 )
	  {
		  exp = inv[i]->query("combat_exp"); 
		  if( exp > top_exp )
		  { 
			sec_exp=top_exp; sec_id = top_id; 
			top_exp = exp; top_id = inv[i]->query("id");
		  }
		  if( exp >sec_exp && exp < top_exp ){ sec_exp=exp; sec_id = inv[i]->query("id"); }
		  sum_exp += exp;
		  inv[i]->delete("sjsz");
		  ppl++;
	  }
	 }

	 if(ppl<6)return notify_fail("����������\n");

	 i = sizeof(inv);
	 exp1=top_exp;
	 exp2=sec_exp;
	 team1 = HIW + "Ұ����" + NOR + " " +top_id;
	 team2 = HIR + "��ʨ��" + NOR + " " +sec_id;
     message_vision( HIG"�����˷���$N�����һ��\n"NOR,present(top_id,here) );
	 message_vision( HIG"�����˷���$N����ڶ���\n"NOR,present(sec_id,here) );

	 while(i)
	{
		 i--;
	  if( inv[i] && objectp(inv[i]) && living(inv[i]) && userp(inv[i]) && inv[i]->query("combat_exp") > 80000 )
	  {
		  exp = inv[i]->query("combat_exp"); 
		  if( exp == top_exp || exp == sec_exp )continue;
		  if(exp1 > exp2 && random(4) != 1)
		  {
			  team2 += " "+inv[i]->query("id");
			  exp2 += exp;
			  inv[i]->delete("sjsz");
			  //message_vision( HIG"�����˷���$N����ڶ���\n"NOR,inv[i] );
		  }
		  else
		  {
			  team1 += " "+inv[i]->query("id");
			  exp1 += exp;
			  inv[i]->delete("sjsz");
			  //message_vision( HIG"�����˷���$N�����һ��\n"NOR,inv[i] );
		  }
	  }
	 }
	 message_vision( HIG"��������$N���������һ�Ӿ�������:"+exp1+"�ڶ��Ӿ�������:"+exp2+"\n"NOR,me);


	 board->delete("team");
	 board->delete("counts");
	 board->delete("east");
	 board->delete("west");
	 board->save();

	 call_out("do_add",1,team2);
	 start_busy(5);
	 return do_add(team1);
}


